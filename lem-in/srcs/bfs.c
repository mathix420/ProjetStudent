/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:07:49 by agissing          #+#    #+#             */
/*   Updated: 2019/02/20 18:07:48 by agissing         ###   ########.fr       */
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
//	printf("trace_new_path %d\n", tmp->room->depth);
	e->end_ptr->nb_ant =  0;
	while (tmp->room->id != e->info.end_id)
	{
		next = tmp->next;
		i = -1;
		while (++i < tmp->nb_next)
		{
//			printf("Test :: %d == %d  %s\n", next[i]->room->depth ,tmp->room->depth - 1, next[i]->room->name);
			if (next[i]->room->depth == (tmp->room->depth - 1)
				&& !next[i]->room->nb_ant)
				break;
		}
		if (i == tmp->nb_next)
		{
//			printf("ESCAPE\n");
			break;
		}
		tmp->room->depth = 0;
		tmp = next[i];
		tmp->room->nb_ant = id;
	}
}

void		unlock_new(t_env *e, t_node *start, int id)
{
	int		i;
	t_node	*tmp;

	i = -1;
	tmp = start;
	printf("START = %s\n", start->room->name);
	while (++i < tmp->nb_next)
	{
		printf("%d\n", tmp->next[i]->room->nb_ant);
		if (start != tmp->next[i]
			&& tmp->next[i]->room->nb_ant
			&& tmp->next[i]->nb_next > 0)
		{
			printf("OK %s\n", tmp->next[i]->room->name);
			tmp->next[i]->room->nb_ant = 0;
			while (e->queue)
				dequeue(e);
			bfs(e, tmp->next[i], id);
			return ;
		}
		else if (tmp->next[i]->room->nb_ant)
			tmp = tmp->next[i]; 
	}
}

void		bfs(t_env *e, t_node *start, int id)
{
	int		i;

	clean_depth(e);
	enqueue(e, start);
	start->room->depth = 1;
	printf("ADD %s\n", e->queue->node->room->name);
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
				if (!e->queue->node->next[i]->room->id)
				{
					trace_new_path(e, e->queue->node->next[i], id++);
					unlock_new(e, start, id);
					return ;
				}
			}
		dequeue(e);
	}
}
