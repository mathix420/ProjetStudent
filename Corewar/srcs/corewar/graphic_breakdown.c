/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_breakdown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 12:45:06 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/13 12:59:33 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

int		compute_total_lives(t_arena *arena)
{
	t_champion	*champion;
	int			total_lives;

	total_lives = 0;
	champion = arena->champion;
	while (champion)
	{
		total_lives += champion->period_live_nb;
		champion = champion->next;
	}
	return (total_lives);
}

void	print_champion_repartition(t_arena *arena, int i, int total_lives)
{
	t_champion	*champion;
	double		cnt;
	int			j;

	j = 3;
	champion = arena->champion;
	while (champion)
	{
		cnt = ((double)champion->period_live_nb / total_lives) * 44.0;
		wattron(arena->ncurses->infos, COLOR_PAIR(champion->color + 1));
		while (cnt-- > 0.5)
			mvwprintw(arena->ncurses->infos, i, j++, "-");
		champion = champion->next;
	}
}

void	print_no_lives_repartition(t_arena *arena, int i)
{
	int		j;
	int		cnt;

	cnt = 0;
	j = 3;
	wattron(arena->ncurses->infos, COLOR_PAIR(1));
	while (cnt++ < 44)
		mvwprintw(arena->ncurses->infos, i, j++, "-");
}

void	print_infos_live_breakdown(t_arena *arena, int *i)
{
	double		total_lives;

	mvwprintw(arena->ncurses->infos, (*i)++, 2,
			"Live breakdown for current period :");
	mvwprintw(arena->ncurses->infos, *i, 2, "[");
	if ((total_lives = compute_total_lives(arena)))
		print_champion_repartition(arena, *i, total_lives);
	else
		print_no_lives_repartition(arena, *i);
	wattron(arena->ncurses->infos, COLOR_PAIR(1));
	mvwprintw(arena->ncurses->infos, *i, 47, "]");
	(*i) += 4;
}
