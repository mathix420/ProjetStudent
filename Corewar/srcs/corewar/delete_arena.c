/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:59:23 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/15 18:18:55 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"

static void	delete_process(t_process *process)
{
	t_process *tmp_process;

	while (process)
	{
		tmp_process = process->next;
		free(process);
		process = tmp_process;
	}
}

static void	delete_champion(t_champion *champion)
{
	t_champion *tmp_champion;

	while (champion)
	{
		tmp_champion = champion->next;
		free(champion);
		champion = tmp_champion;
	}
}

void		delete_arena(t_arena *arena)
{
	delete_champion(arena->champion);
	delete_process(arena->process);
	free(arena);
}

void		delete_last_arena(t_arena *arena)
{
	t_arena *last_arena;
	t_arena *tmp_arena;

	(*arena->size_list)--;
	last_arena = arena;
	while (last_arena->next && last_arena->next->next)
		last_arena = last_arena->next;
	tmp_arena = last_arena;
	last_arena = last_arena->next;
	delete_arena(last_arena);
	tmp_arena->next = NULL;
}

void		delete_list_arena(t_arena *arena)
{
	t_arena		*tmp_arena;
	WINDOW		*free_corewar;
	WINDOW		*free_infos;

	while (arena)
	{
		tmp_arena = arena->next;
		if (!arena->next)
		{
			free(arena->size_list);
			free(arena->champion->name);
			free(arena->champion->comment);
			if (arena->ncurses && arena->ncurses->corewar && arena->ncurses->infos)
			{
				free_corewar = arena->ncurses->corewar;
				free_infos = arena->ncurses->infos;
				free(arena->ncurses);
			}
		}
		delete_arena(arena);
		arena = tmp_arena;
	}
}
