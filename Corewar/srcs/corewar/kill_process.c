/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:35:13 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/08 18:35:58 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"

static void	delete_process(t_arena *arena, t_process *process, t_process *prev_process)
{
	if (prev_process)
		prev_process->next = process->next;
	else
		arena->process = process->next;
	arena->total_process -= 1;
	free(process);
}

void		kill_no_live_process(t_arena *arena)
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
