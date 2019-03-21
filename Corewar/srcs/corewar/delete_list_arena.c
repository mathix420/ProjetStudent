/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list_arena.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <trlevequ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:34:33 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/20 15:49:14 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "corewar.h"

void		delete_data_champions(t_arena *arena)
{
	t_champion	*champion;

	champion = arena->champion;
	while (champion)
	{
		free(champion->name);
		free(champion->comment);
		champion = champion->next;
	}
}

void		delete_list_arena(t_arena *arena)
{
	t_arena			*tmp_arena;
	t_win			*free_corewar;
	t_win			*free_infos;

	while (arena)
	{
		tmp_arena = arena->next;
		if (!arena->next)
		{
			delete_data_champions(arena);
			free(arena->size_list);
			if (arena->ncurses && arena->ncurses->corewar
					&& arena->ncurses->infos)
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
