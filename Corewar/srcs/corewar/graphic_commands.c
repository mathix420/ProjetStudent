/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:00:59 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/11 14:01:57 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

static int			manage_space_key(t_arena *arena, char ch)
{
	if (ch == ' ' && arena->ncurses->break_step)
		return (1);
	else if (ch == ' ' && !arena->ncurses->pause && !arena->ncurses->break_step)
	{
		arena->ncurses->pause = 1;
		timeout(1000000);
		return (1);
	}
	else if (ch == ' ' && arena->ncurses->pause && !arena->ncurses->break_step)
	{
		arena->ncurses->pause = 0;
		timeout(0);
		return (1);
	}
	return (0);
}

void				get_ncurses_commands(t_arena *arena)
{
	char ch;

	ch = getch();
	if (manage_space_key(arena, ch))
		return ;
	else if (ch == 'm' && !arena->ncurses->break_step)
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
	else if (arena->ncurses->pause || arena->ncurses->break_step)
		get_ncurses_commands(arena);
}
