/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:00:59 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/12 13:44:43 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

static int			manage_space_key(t_arena *arena, int ch)
{
	if (ch == ' ' && arena->ncurses->break_step)
		return (1);
	else if (ch == ' ' && !arena->ncurses->pause && !arena->ncurses->break_step)
	{
		arena->ncurses->pause = 1;
		timeout(1000000);
		return (0);
	}
	else if (ch == ' ' && arena->ncurses->pause && !arena->ncurses->break_step)
	{
		arena->ncurses->pause = 0;
		timeout(0);
		return (1);
	}
	return (0);
}

static void			manage_m_key(t_arena *arena, int ch)
{
	if (ch == 'm' && !arena->ncurses->break_step)
	{
		arena->ncurses->break_step = 1;
		timeout(1000000);
	}
	else if (ch == 'm' && arena->ncurses->break_step)
	{
		arena->ncurses->break_step = 0;
		arena->ncurses->pause = 1;
		timeout(1000000);
	}
}

static void			manage_arrows_key(t_arena *arena, int ch)
{
	if (ch == KEY_UP && arena->cycle_per_sec < 1000)
		arena->cycle_per_sec = arena->cycle_per_sec + 1;
	else if (ch == KEY_DOWN && arena->cycle_per_sec > 1)
		arena->cycle_per_sec = arena->cycle_per_sec - 1;
}

static int			is_other_key(t_arena *arena, int ch)
{
	if (arena->ncurses->pause || arena->ncurses->break_step || ch == ' '
			|| ch == 'm' || ch == KEY_UP || ch == KEY_DOWN)
		return (0);
	return (1);
}

void				get_ncurses_commands(t_arena *arena)
{
	int ch;

	while (1)
	{
		ch = getch();
		if (manage_space_key(arena, ch))
			return ;
		manage_m_key(arena, ch);
		manage_arrows_key(arena, ch);
		if (is_other_key(arena, ch))
			return ;
		print_graphic_infos(arena);
		wrefresh(arena->ncurses->infos);
	}
}
