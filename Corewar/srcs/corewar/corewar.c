/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:56:52 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/12 15:47:42 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
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

void	cycle_to_die_verif(t_arena *arena)
{
	kill_no_live_process(arena);
	//add + 1 to ttal lives when live instruction == 1
	if (arena->total_lives >= NBR_LIVE)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->last_check = arena->cycle;
	}
	arena->total_lives = 0;
	if (arena->cycle - arena->last_check > MAX_CHECKS)
	{
		arena->cycle_to_die -= CYCLE_DELTA;
		arena->last_check = arena->cycle;
	}
}

int		corewar(t_arena *arena)
{
	clock_t current_clock;

	current_clock = clock();
	while (arena->total_process)
	{
		if (clock() - current_clock >= (1000000) / arena->cycle_per_sec)
	
		{
			current_clock = clock();
			check_all_process(arena);
			print_graphic(arena);
			arena->cycle++;
			if (arena->cycle % arena->cycle_to_die == 0)
				cycle_to_die_verif(arena);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = create_arena(ac, av);
	init_graphic(arena);
	corewar(arena);
//	print_map(arena->map);
	usleep(100000);
	endwin();
	return (0);
}
