/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:29:24 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/22 20:33:45 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			clean_ant(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		if (tmp->nb_ant != 1 && !tmp->lock)
			tmp->nb_ant = 0;
		tmp = tmp->next;
	}
}

void				init_resolution(t_env *e)
{
	t_node	*start;
	t_node	*tmp_2;
	int		tmp;
	int		save;
	int		solve_id;
	int		i;

	tmp = -2;
	i = -1;
	e->count = 0;
	solve_id = 0;
	if (!(e->tab_size = (int *)ft_memalloc(sizeof(int) * e->room->node->nb_next)))
		return ;
	if (!(e->tab_ant = (int *)ft_memalloc(sizeof(int) * e->room->node->nb_next)))
		return ;
	while (1)
	{
		i = -1;
		e->steps = -1;
		start = e->room->node;
		tmp_2 = NULL;
		bfs(e, e->room->node, solve_id);
		e->count++;
		printf("\n\n=========== CALL %d ==============\n", e->count);
		printf("steps => %d\n", e->steps);
		print_room(e);
		print_tab(e);
		if (e->steps != -1 && (tmp == -2 || tmp > e->steps))
		{
			solve_id++;
			tmp = e->steps;
			save = e->count;
		}
		ft_bzero(e->tab_ant, sizeof(int) * e->room->node->nb_next);
		ft_bzero(e->tab_size, sizeof(int) * e->room->node->nb_next);
		while (++i < start->nb_next)
		{
			if (start->next[i]->room->nb_ant == 1 && start->next[i]->room->id != e->info.end_id && (start->next[i] != tmp_2 || !tmp_2))
			{
				tmp_2 = start;
				start = start->next[i]->room->node;
				i = -1;
			}
		}
		clean_ant(e);
		if (start->room->id == e->info.start_id)
			break ;
		else
		{
			start->room->nb_ant = 0;
			printf("removing room %s\n", start->room->name);
		}
	}
	printf("\n\n|||| BEST CHOICE = CALL %d ||||\n", save);
}
