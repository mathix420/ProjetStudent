/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:38:59 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/28 18:13:21 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_cycle_decount(t_process *process)
{
	(void)process;
}

void	check_process(t_process *process)
{
	if (!process->cycle_decount)
	{
		init_cycle_decount(process);
		return ;
	}
	else
		process->cycle_decount--;
}

void	check_all_process(t_arena *arena)
{
	t_champion	*champion;
	t_process	*process;

	champion = arena->champion;
	while (champion)
	{
		process = champion->process;
		while (process)
		{
			check_process(process);
			process = process->next;
		}
		champion = champion->next;
	}
}

int		corewar(t_arena *arena)
{
	while (arena->total_process)
	{
		ft_putstr("It's now cycle: ");
		ft_putnbr(arena->cycle);
		ft_putchar('\n');
		check_all_process(arena);
		arena->cycle++;
		if (arena->cycle % arena->cycle_to_die == 0)
			break ;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = create_arena(ac, av);
	print_op_tab(arena);
	//corewar(arena);
	//print_map(arena->map);
	//print_structure(*arena, arena->map);
	return (0);
}
