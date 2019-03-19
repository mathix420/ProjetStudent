/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:56:52 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/18 18:21:50 by trlevequ         ###   ########.fr       */
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

void	check_process(t_process *process)
{
	if (process->cycle_decount > 1)
		process->cycle_decount--;
	else if (process->cycle_decount == 1)
	{
		launch_valid_function(process);
		get_current_instruction(process);
	}
	else if (process->cycle_decount == 0)
		get_current_instruction(process);
}

void	check_all_process(t_arena *arena)
{
	t_process	*process;

	process = arena->process;
	while (process)
	{
		check_process(process);
		process = process->next;
	}
}

void	cycle_to_die_verif(t_arena *arena)
{
	kill_no_live_processes(arena);
	if (arena->total_lives >= NBR_LIVE)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->nb_checks = 0;
	}
	else
		arena->nb_checks++;
	fill_zero_period_live(arena);
	if (arena->nb_checks == MAX_CHECKS)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->nb_checks = 0;
	}
	arena->total_lives = 0;
	arena->cycle_decount = arena->cycle_to_die;
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
		if (arena->cycle_decount <= 1)
			cycle_to_die_verif(arena);
		else
			arena->cycle_decount--;
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

void	gagnant(t_arena *arena)
{
	t_champion	*champion;
	t_champion	*gagnant;
	int			i;

	champion = arena->champion;
	gagnant = champion;
	while (champion)
	{
		if (gagnant->last_live <= champion->last_live)
			gagnant = champion;
		champion = champion->next;
	}
	i = 1;
	champion = arena->champion;
	while (champion != gagnant)
	{
		i++;
		champion = champion->next;
	}
	ft_putstr("Contestant ");
	ft_putnbr(i);
	ft_putstr(", \"");
	ft_putstr(gagnant->name);
	ft_putstr("\", has won !\n");
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
		gagnant(arena);
		delete_list_arena(arena);
	}
	return (0);
}
