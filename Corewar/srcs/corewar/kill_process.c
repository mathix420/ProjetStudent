/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:35:13 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/11 14:16:57 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"

void	delete_process(t_arena *arena, t_process *prcs, t_process *prev_prcs)
{
	if (prev_prcs)
		prev_prcs->next = prcs->next;
	else
		arena->process = prcs->next;
	arena->total_process -= 1;
	free(prcs);
}

void	kill_no_live_process(t_arena *arena)
{
	t_process *process;
	t_process *prev_process;

	process = arena->process;
	prev_process = NULL;
	while (process)
	{
		if (!process->alive)
			delete_process(arena, process, prev_process);
		else
			process->alive = 0;
		prev_process = process;
		process = process->next;
	}
}
