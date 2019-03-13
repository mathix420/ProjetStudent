/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:29:56 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/13 14:27:11 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

void				print_infos_commands(t_arena *arena, int *i)
{
	mvwprintw(arena->ncurses->infos, *i, 2, "** Commands **", MAX_CHECKS);
	*i += 2;
	if (arena->ncurses->break_step)
		mvwprintw(arena->ncurses->infos, *i, 2, "Cycle mode (key='m') : space");
	else
		mvwprintw(arena->ncurses->infos, *i, 2, "Cycle mode (key='m') : auto ");
	*i += 2;
	mvwprintw(arena->ncurses->infos, *i, 2, "Cycle_per_sec (key='UP/DOWN')");
}

void				print_infos_defines(t_arena *arena, int *i)
{
	mvwprintw(arena->ncurses->infos, *i, 2,
			"CYCLE_TO_DIE : %-4d", arena->cycle_to_die);
	*i += 2;
	mvwprintw(arena->ncurses->infos, *i, 2, "CYCLE_DELTA : %d", CYCLE_DELTA);
	*i += 2;
	mvwprintw(arena->ncurses->infos, *i, 2, "NBR_LIVE : %d", NBR_LIVE);
	*i += 2;
	mvwprintw(arena->ncurses->infos, *i, 2, "MAX_CHECKS : %d", MAX_CHECKS);
	*i += 4;
}

void				print_infos_players(t_arena *arena, int *i)
{
	t_champion	*champion;

	champion = arena->champion;
	*i = 13;
	while (champion)
	{
		wattron(arena->ncurses->infos,
				COLOR_PAIR(champion->color + 1) | A_BOLD);
		mvwprintw(arena->ncurses->infos, (*i)++, 2, champion->name);
		wattron(arena->ncurses->infos, COLOR_PAIR(1) | A_BOLD);
		mvwprintw(arena->ncurses->infos, (*i)++, 5,
				"Last live : %d", champion->last_live);
		mvwprintw(arena->ncurses->infos, (*i)++, 5,
				"Lives in current period : %-4d", champion->period_live_nb);
		++(*i);
		champion = champion->next;
	}
	(*i) += 2;
}

void				print_graphic_infos(t_arena *arena)
{
	int			i;

	i = 10;
	wattron(arena->ncurses->infos, COLOR_PAIR(1) | A_BOLD);
	if (arena->ncurses->pause)
		mvwprintw(arena->ncurses->infos, 2, 1, "** PAUSED **");
	else
		mvwprintw(arena->ncurses->infos, 2, 1, "** RUNNING **");
	mvwprintw(arena->ncurses->infos, 5, 2, "Cycles_per_second : %-4d",
			arena->cycle_per_sec);
	mvwprintw(arena->ncurses->infos, 7, 2, "Cycle : %d", arena->cycle);
	mvwprintw(arena->ncurses->infos, 9, 2, "Processes : %-4d",
			arena->total_process);
	print_infos_players(arena, &i);
	print_infos_live_breakdown(arena, &i);
	print_infos_defines(arena, &i);
	print_infos_commands(arena, &i);
}
