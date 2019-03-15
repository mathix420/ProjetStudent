/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:00:59 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/15 18:32:08 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ncurses.h>
#include "corewar.h"

static int	manage_space_key(t_arena *arena, int ch)
{
	if (ch == ' ' && !arena->ncurses->pause)
	{
		arena->ncurses->pause = 1;
		timeout(1000000);
	}
	else if (ch == ' ' && arena->ncurses->pause)
	{
		arena->ncurses->pause = 0;
		timeout(0);
		return (1);
	}
	return (0);
}

static int	manage_qwer_key(t_arena *arena, int ch)
{
	if (ch == 'r' && arena->cycle_per_sec <= 990)
		arena->cycle_per_sec = arena->cycle_per_sec + 10;
	else if (ch == 'e' && arena->cycle_per_sec < 1000)
		arena->cycle_per_sec = arena->cycle_per_sec + 1;
	else if (ch == 'w' && arena->cycle_per_sec > 1)
		arena->cycle_per_sec = arena->cycle_per_sec - 1;
	else if (ch == 'q' && arena->cycle_per_sec > 10)
		arena->cycle_per_sec = arena->cycle_per_sec - 10;
	return ((arena->ncurses->pause) ? 0 : 1);
}

int			manage_arrows_key(t_arena **arena, int ch)
{
	int		i;
	t_arena *tmp;

	i = -1;
	if (!(*arena)->ncurses->pause)
		return (0);
	if (ch == KEY_LEFT)
	{
		while (++i < 2)
			if ((*arena)->next)
			{
				(*(*arena)->size_list)--;
				tmp = (*arena)->next;
				delete_arena(*arena);
				*arena = tmp;
			}
		return (0);
	}
	else if (ch == KEY_RIGHT)
		return (1);
	return (0);
}

void		get_ncurses_commands(t_arena **arena)
{
	int ch;

	while (1)
	{
		ch = getch();
		if (manage_space_key(*arena, ch))
			return ;
		else if (manage_qwer_key(*arena, ch))
			return ;
		if (manage_arrows_key(arena, ch))
			return ;
		print_graphic_corewar(*arena);
		print_graphic_infos(*arena);
		wrefresh((*arena)->ncurses->corewar);
		wrefresh((*arena)->ncurses->infos);
	}
}
