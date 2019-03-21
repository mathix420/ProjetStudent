/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:03:37 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/20 16:11:11 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
