/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <trlevequ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:42:56 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/20 15:27:05 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

void	print_graphic_winner(t_arena *arena, t_champion *winner)
{
	wattron(arena->ncurses->infos, COLOR_PAIR(1));
	mvwprintw(arena->ncurses->infos, 55, 2, "The winner is : ");
	wattron(arena->ncurses->infos, COLOR_PAIR(winner->color + 1));
	mvwprintw(arena->ncurses->infos, 55, 18, "%s", winner->name);
	wattron(arena->ncurses->infos, COLOR_PAIR(1));
	mvwprintw(arena->ncurses->infos, 57, 2, "Press any key to finish");
	wrefresh(arena->ncurses->corewar);
	wrefresh(arena->ncurses->infos);
	timeout(1000000);
	getch();
}
