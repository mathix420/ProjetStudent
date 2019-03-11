/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:56:52 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/11 14:05:26 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "corewar.h"

void	check_process(t_process *process)
{
	if (process->cycle_decount > 1)
		process->cycle_decount--;
	else if (process->cycle_decount == 1)
	{
		get_param_instruction(process);
		g_op_tab[process->index].function(process);
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

int		corewar(t_arena *arena)
{
	while (arena->total_process)
	{
		check_all_process(arena);
		print_graphic(arena);
		arena->cycle++;
		if (arena->cycle % arena->cycle_to_die == 0)
			kill_no_live_process(arena);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = create_arena(ac, av);
	init_graphic(arena);
	corewar(arena);
	usleep(100000);
	endwin();
	return (0);
}
