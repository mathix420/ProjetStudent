/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:07:49 by agissing          #+#    #+#             */
/*   Updated: 2019/02/22 20:32:06 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

inline void		clean_depth(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		tmp->depth = 0;
		tmp = tmp->next;
	}
}

static int		fill_tab_ant(t_env *e, int max, int id)
{
	int		nb_ant;
	int		i;

	nb_ant = e->info.nb_ant;
	while (nb_ant)
	{
		i = -1;
		while (++i <= id - e->count && nb_ant)
		{
			if ((e->tab_size[i] + e->tab_ant[i] - 1) < max && (!e->count || i))
			{
				e->tab_ant[i]++;
				nb_ant--;
				i = -1;
			}
		}
		max++;
	}
	return (max);
}

static int		get_weigth(t_env *e, int path_size, int id)
{
	int		nb_ant;
	int		max;
	int		i;

	i = -1;
	max = 0;
	nb_ant = e->info.nb_ant;
	while (++i < id)
	{
		e->tab_ant[i] = 0;
		if ((!max || e->tab_size[i] < max) && (!e->count || i))
			max = e->tab_size[i];
	}
	e->tab_size[id] = path_size - 2;
	max = fill_tab_ant(e, max, id);
	if (e->steps == -1 || max <= e->steps)
		return (e->steps = max);
	return (0);
}

static int		trace_new_path(t_env *e, t_node *start, t_node *end, int id)
{
	int			i;
	t_node		**next;

	e->lock_var++;
	printf("id :: %d == %d\n", id, e->count);
	if (!(get_weigth(e, end->room->depth, id - 1)))
		return (0);
	start->room->nb_ant = 0;
	while (end->room->id != e->info.start_id)
	{
		next = end->next;
		i = -1;
		while (++i < end->nb_next)
			if (next[i]->room->depth == (end->room->depth - 1)
				&& !next[i]->room->nb_ant)
				break ;
		if (i == end->nb_next)
			break ;
		end->room->depth = 0;
		end = next[i];
		if (e->count > 0 && !e->lock_var)
			end->room->lock = 1;
		end->room->nb_ant = id;
	}
	return (1);
}

int				bfs(t_env *e, t_node *start, int id)
{
	int		i;
	int		j;

	e->lock_var = -1;
	clean_depth(e);
	enqueue(e, start);
	start->room->depth = 1;
	while (e->queue)
	{
		i = -1;
		while (++i < e->queue->node->nb_next)
			if (!e->queue->node->next[i]->room->depth
				&& !e->queue->node->next[i]->room->nb_ant)
			{
				enqueue(e, e->queue->node->next[i]);
				e->queue->node->next[i]->room->depth
				   	= e->queue->node->room->depth + 1;
				if (e->queue->node->next[i]->room->id == e->info.end_id)
				{
					j = trace_new_path(e, start, e->queue->node->next[i], ++id);
					e->queue->node->next[i]->room->nb_ant = 0;
					e->queue->node->next[i]->room->depth = 0;
					clear_queue(e);
					return (j && bfs(e, start, id));
				}
			}
		dequeue(e);
	}
	return (0);
}
