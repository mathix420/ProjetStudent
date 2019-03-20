/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:06:54 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/20 15:23:20 by trlevequ         ###   ########.fr       */
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

void				print_graphic_pc(t_arena *arena)
{
	t_process	*process;
	int			index;
	int			i;
	int			j;

	process = arena->process;
	while (process)
	{
		index = (int)(process->pc - arena->map);
		i = (index / 128);
		j = (index % 128) + ((index % 128) / 2);
		wattron(arena->ncurses->corewar,
				COLOR_PAIR(arena->map[index].color + 6));
		mvwaddch(arena->ncurses->corewar, i + 1, j + 2, arena->map[index].hex);
		mvwaddch(arena->ncurses->corewar, i + 1, j + 3,
				arena->map[index + 1].hex);
		process = process->next;
	}
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
	print_graphic_pc(arena);
}

void				print_graphic(t_arena **arena)
{
	print_graphic_corewar(*arena);
	print_graphic_infos(*arena);
	wrefresh((*arena)->ncurses->corewar);
	wrefresh((*arena)->ncurses->infos);
	if (!(*arena)->process)
		print_graphic_winner(*arena, winner(*arena));
	else
		get_ncurses_commands(arena);
}
