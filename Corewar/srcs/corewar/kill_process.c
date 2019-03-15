/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:35:13 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/15 14:31:32 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"

void	delete_process(t_arena *arena, t_process **prcs, t_process *prev_prcs)
{
	t_process	*prcs_next;

	prcs_next = (*prcs)->next;
	if (prev_prcs)
		prev_prcs->next = (*prcs)->next;
	else
		arena->process = (*prcs)->next;
	arena->total_process -= 1;
	if (arena->map[(int)((*prcs)->pc - arena->map)].color >= 5)
		arena->map[(int)((*prcs)->pc - arena->map)].color -= 5;
	free(*prcs);
	*prcs = prcs_next;
}

void	kill_no_live_processes(t_arena *arena)
{
	t_process *process;
	t_process *prev_process;

	process = arena->process;
	prev_process = NULL;
	while (process)
	{
		if (!process->alive)
			delete_process(arena, &process, prev_process);
		else
		{
			process->alive = 0;
			prev_process = process;
			process = process->next;
		}
	}
}

void	fill_zero_period_live(t_arena *arena)
{
	t_champion *champion;

	champion = arena->champion;
	while (champion)
	{
		champion->period_live_nb = 0;
		champion = champion->next;
	}
}
