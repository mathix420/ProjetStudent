/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:06:54 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/12 13:52:39 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

void				set_attron_color(WINDOW *corewar, t_arena *arena, int i)
{
	t_process	*process;

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
	if (arena->map[i].color >= 0 && arena->map[i].color <= 4)
	{
		if (arena->map[i].bold_decount)
		{
			wattron(corewar, COLOR_PAIR(arena->map[i].color + 1) | A_BOLD);
			arena->map[i].bold_decount--;
			arena->map[i + 1].bold_decount--;
		}
		else
			wattron(corewar, COLOR_PAIR(arena->map[i].color + 1));
	}
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
		wattroff(arena->ncurses->corewar, A_BOLD);
		i += 2;
		end_of_line(arena, &j, &k);
	}
}

void				print_graphic(t_arena *arena)
{
	print_graphic_corewar(arena);
	print_graphic_infos(arena);
	wrefresh(arena->ncurses->corewar);
	wrefresh(arena->ncurses->infos);
	get_ncurses_commands(arena);
}
