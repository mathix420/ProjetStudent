/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:06:54 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/08 17:17:19 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "corewar.h"

void				set_attron_color(WINDOW *corewar, t_arena *arena, int i)
{
	t_process *process;

	process = arena->process;
	while (process)
	{
		if (&(arena->map[i]) == process->pc)
		{
			wattron(corewar, COLOR_PAIR(arena->map[i].color + 6));
			return ;
		}
		process = process->next;
	}
	if (arena->map[i].color == 0)
		wattron(corewar, COLOR_PAIR(1));
	else if (arena->map[i].color == 1)
		wattron(corewar, COLOR_PAIR(2));
	else if (arena->map[i].color == 2)
		wattron(corewar, COLOR_PAIR(3));
	else if (arena->map[i].color == 3)
		wattron(corewar, COLOR_PAIR(4));
	else if (arena->map[i].color == 4)
		wattron(corewar, COLOR_PAIR(5));
}

void				print_graphic_infos(t_arena *arena)
{
	t_champion	*champion;
	int			i;

	i = 10;
	wattron(arena->ncurses->infos, COLOR_PAIR(1) | A_BOLD);
	mvwprintw(arena->ncurses->infos, 1, 10, "INFOS");
	mvwprintw(arena->ncurses->infos, 5, 2, "Cycle : %d", arena->cycle);
	mvwprintw(arena->ncurses->infos, 8, 2, "Processes : %d", arena->total_process);
	champion = arena->champion;
	while (champion)
	{
		wattron(arena->ncurses->infos, COLOR_PAIR(1) | A_BOLD);
		mvwprintw(arena->ncurses->infos, i++, 2, champion->name);
		wattron(arena->ncurses->infos, COLOR_PAIR(1) | A_BOLD);
		mvwprintw(arena->ncurses->infos, i++, 5, "Last live : %d", champion->last_live);
		mvwprintw(arena->ncurses->infos, i++, 5, "Last live : %d", champion->period_live_nb);
		++i;
		champion = champion->next;	
	}
	i++;
	mvwprintw(arena->ncurses->infos, i, 2, "CYCLE_TO_DIE : %d", CYCLE_TO_DIE);
	i += 2;
	mvwprintw(arena->ncurses->infos, i, 2, "CYCLE_DELTA : %d", CYCLE_DELTA);
	i += 2;
	mvwprintw(arena->ncurses->infos, i, 2, "NBR_LIVE : %d", NBR_LIVE);
	i += 2;
	mvwprintw(arena->ncurses->infos, i, 2, "MAX_CHECKS : %d", MAX_CHECKS);
}

static inline void	end_of_line(t_arena *arena, int *j, int *k)
{
	if ((*j + 3) >= arena->ncurses->width_line - 1)
	{
		*j = -3;
		++(*k);
	}
	else
	{
		wattron(arena->ncurses->corewar, COLOR_PAIR(1));
		mvwaddch(arena->ncurses->corewar, *k + 1, *j + 4, ' ');
	}
	*j += 3;
}

void				print_graphic_corewar(t_arena *arena)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < MEM_SIZE * 2)
	{
		set_attron_color(arena->ncurses->corewar, arena, i);
		mvwaddch(arena->ncurses->corewar, k + 1, j + 2, arena->map[i].hex);
		mvwaddch(arena->ncurses->corewar, k + 1, j + 3, arena->map[i + 1].hex);
		i += 2;
		end_of_line(arena, &j, &k);
	}
	print_graphic_infos(arena);
	wrefresh(arena->ncurses->corewar);
	wrefresh(arena->ncurses->infos);
	usleep(10000);
}

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
	arena->ncurses->infos = subwin(stdscr, arena->ncurses->height_line + 2, 50, 0,
			arena->ncurses->width_line + 4);
}

void				init_graphic(t_arena *arena)
{
	initscr();
	init_ncurses_color();
	create_ncurses_struct(arena);
	curs_set(0);
	box(arena->ncurses->corewar, ACS_VLINE, ACS_HLINE);
	box(arena->ncurses->infos, ACS_VLINE, ACS_HLINE);
}

