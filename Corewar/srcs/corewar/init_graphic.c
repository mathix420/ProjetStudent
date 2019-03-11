/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:25:17 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/11 14:14:42 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

void				init_ncurses_color(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_WHITE, COLOR_GREEN);
	init_pair(8, COLOR_WHITE, COLOR_RED);
	init_pair(9, COLOR_WHITE, COLOR_CYAN);
	init_pair(10, COLOR_WHITE, COLOR_YELLOW);
}

void				create_ncurses_struct(t_arena *arena)
{
	if (!(arena->ncurses = (t_ncurses *)malloc(sizeof(t_ncurses))))
		exit(0);
	arena->ncurses->width_line = (64 * 3) - 1;
	arena->ncurses->height_line = MEM_SIZE / 64;
	arena->ncurses->corewar = subwin(stdscr, arena->ncurses->height_line + 2,
			arena->ncurses->width_line + 4, 0, 0);
	arena->ncurses->infos = subwin(stdscr, arena->ncurses->height_line + 2,
			50, 0, arena->ncurses->width_line + 4);
	arena->ncurses->pause = 1;
	arena->ncurses->break_step = 0;
}

void				init_graphic(t_arena *arena)
{
	initscr();
	keypad(stdscr, TRUE);
	init_ncurses_color();
	create_ncurses_struct(arena);
	curs_set(0);
	noecho();
	cbreak();
	timeout(100000);
	box(arena->ncurses->corewar, ACS_VLINE, ACS_HLINE);
	box(arena->ncurses->infos, ACS_VLINE, ACS_HLINE);
}
