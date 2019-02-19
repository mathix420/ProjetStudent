/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:07:49 by agissing          #+#    #+#             */
/*   Updated: 2019/02/19 23:11:14 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clean_depth(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		tmp->depth = 0;
		tmp = tmp->next;
	}
}

void		trace_new_path(t_env *e, t_node *start, int id)
{
	int			i;
	t_node		*tmp;
	t_node		**next;

	tmp = start;
	printf("trace_new_path\n");
	while (tmp->room->id != e->info.end_id)
	{
		next = tmp->next;
		i = -1;
		while (++i < tmp->nb_next)
		{
			if (next[i]->room->depth == tmp->room->depth - 1)
				break;
		}
		tmp = next[i];
		tmp->room->nb_ant = id;
		tmp->room->depth = 0;
	}
}

void		bfs(t_env *e, t_node *start)
{
	int		i;
	int		id;

	clean_depth(e);
	enqueue(e, start);
	start->room->depth = 1;
	id = 1;
	while (e->queue)
	{
		i = -1;
		printf("ADD %s\n", e->queue->node->room->name);
		if (!e->queue->node->room->id)
			trace_new_path(e, e->queue->node, id++);
		while (++i < e->queue->node->nb_next)
			if (!e->queue->node->next[i]->room->depth
				&& !e->queue->node->next[i]->room->nb_ant)
			{
				enqueue(e, e->queue->node->next[i]);
				e->queue->node->next[i]->room->depth
					= e->queue->node->room->depth + 1;
			}
		dequeue(e);
	}
}
