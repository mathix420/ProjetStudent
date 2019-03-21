/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:56:52 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/20 16:09:54 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include "corewar.h"

void	launch_valid_function(t_process *process)
{
	if (!process->encodage)
	{
		get_param_instruction(process);
		g_op_tab[process->index].function(process);
	}
	else
	{
		process->valid_encodage = 1;
		check_encodage(process);
		if (process->valid_encodage)
		{
			get_param_instruction(process);
			g_op_tab[process->index].function(process);
		}
		else
			g_op_tab[16].function(process);
	}
}

int		corewar_graphic(t_arena **arena)
{
	clock_t current_clock;

	current_clock = clock();
	while ((*arena)->total_process)
	{
		if (clock() - current_clock >= (1000000) / (*arena)->cycle_per_sec)
		{
			current_clock = clock();
			check_all_process(*arena);
			print_graphic(arena);
			add_cycle_to_list(arena);
			(*arena)->cycle++;
			if ((*arena)->cycle_decount <= 1)
				cycle_to_die_verif(*arena);
			else
				(*arena)->cycle_decount--;
		}
	}
	return (0);
}

int		corewar(t_arena *arena)
{
	while (arena->total_process)
	{
		if (arena->dump == arena->cycle)
		{
			print_map(arena->map);
			ft_putstr("\nDump at cycle ");
			ft_putnbr(arena->cycle);
			ft_putendl("");
			arena->dump = -1;
			break ;
		}
		check_all_process(arena);
		arena->cycle++;
		(arena->cycle_decount <= 1) ? cycle_to_die_verif(arena)
			: arena->cycle_decount--;
	}
	if (arena->dump != -1)
	{
		print_map(arena->map);
		ft_putstr("\nDump at cycle ");
		ft_putnbr(arena->cycle);
		ft_putendl("");
	}
	return (0);
}

void	introducing_champs(t_arena *arena)
{
	t_champion	*champion;
	int			i;

	champion = arena->champion;
	ft_putendl("Introducing contestants...");
	i = 1;
	while (champion)
	{
		ft_putstr("* Player ");
		ft_putnbr(i);
		ft_putstr(", weighing ");
		ft_putnbr(champion->size);
		ft_putstr(" bytes, \"");
		ft_putstr(champion->name);
		ft_putstr("\", (\"");
		ft_putstr(champion->comment);
		ft_putstr("\") !\n");
		champion = champion->next;
		i++;
	}
	ft_putendl("");
}

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = create_arena(ac, av);
	if (arena->graphic)
	{
		init_graphic(arena);
		corewar_graphic(&arena);
		print_graphic(&arena);
		endwin();
		delete_list_arena(arena);
	}
	else
	{
		introducing_champs(arena);
		corewar(arena);
		print_winner(arena, winner(arena));
		delete_list_arena(arena);
	}
	return (0);
}
