/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:06:54 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/15 17:30:42 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

void				set_attron_color(WINDOW *corewar, t_arena *arena, int i)
{
	if (arena->map[i].bold_decount)
	{
		wattron(corewar, COLOR_PAIR(arena->map[i].color + 1) | A_BOLD);
		arena->map[i].bold_decount--;
	}
	else
		wattron(corewar, COLOR_PAIR(arena->map[i].color + 1));
}

static inline void	end_of_line(t_arena *arena, int *j, int *k)
{
	if ((*j + 3) >= arena->ncurses->width_line - 1)
	{
		*j = 0;
		++(*k);
	}
	else
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
		wattroff(arena->ncurses->corewar, A_BOLD);
		i += 2;
		end_of_line(arena, &j, &k);
	}
}

void				print_graphic_winner(t_arena *arena)
{
	t_champion	*champion;
	t_champion	*winner;

	if (arena->process)
		return ;
	champion = arena->champion->next;
	winner = arena->champion;
	while (champion)
	{
		if (winner->last_live <= champion->last_live)
			winner = champion;
		champion = champion->next;
	}
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

void				print_graphic(t_arena **arena)
{
	print_graphic_corewar(*arena);
	print_graphic_infos(*arena);
	wrefresh((*arena)->ncurses->corewar);
	wrefresh((*arena)->ncurses->infos);
	get_ncurses_commands(arena);
	print_graphic_winner(*arena);
}
