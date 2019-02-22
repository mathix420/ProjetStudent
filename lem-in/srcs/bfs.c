/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:07:49 by agissing          #+#    #+#             */
/*   Updated: 2019/02/22 16:41:05 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	clean_depth(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		tmp->depth = 0;
		tmp = tmp->next;
	}
}

int			get_weigth(t_env *e, int path_size, int id, int count)
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
		if ((!max || e->tab_size[i] < max) && (!count || i))
			max = e->tab_size[i];
	}
	printf("ID :: %d\n", id);
	e->tab_size[id] = path_size - 2;
	while (nb_ant)
	{
		i = -1;
		while (++i <= id && nb_ant)
		{
			if (((e->tab_size[i] + e->tab_ant[i] - 1) < max) && (!count || i))
			{
				e->tab_ant[i]++;
				nb_ant--;
				i = -1;
			}
		}
		max++;
	}
	if (e->steps == -1 || max <= e->steps)
	{
		printf("OK\n");
		e->steps = max;
		return (1);
	}
	printf("KO\n");
	return (0);
}

static int			trace_new_path(t_env *e, t_node *start, t_node *end, int id, int count)
{
	int			i;
	t_node		*tmp;
	t_node		**next;

	tmp = end;
	if (!(get_weigth(e, end->room->depth, id - 1, count)))
		return (0);
	printf("%d\tNEW PATH :: %s - %d\n", id, tmp->room->name, tmp->room->depth);
	start->room->nb_ant =  0;
	while (tmp->room->id != e->info.start_id)
	{
		next = tmp->next;
		i = -1;
		while (++i < tmp->nb_next)
			if (next[i]->room->depth == (tmp->room->depth - 1)
				&& !next[i]->room->nb_ant)
			{
//				printf("%d\tNEXT :: %s -  %d\n", id, next[i]->room->name, next[i]->room->depth);
				break;
			}
		if (i == tmp->nb_next)
			break;
		tmp->room->depth = 0;
		tmp = next[i];
		tmp->room->nb_ant = id;
	}
	return (1);
}

lock

int					bfs(t_env *e, t_node *start, int id, int count)
{
	int		i;
	int		j;

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
					j = trace_new_path(e, start, e->queue->node->next[i], ++id, count);
					e->queue->node->next[i]->room->nb_ant = 0;
					e->queue->node->next[i]->room->depth = 0;
					start->room->nb_ant = 0;
					clear_queue(e);
					return (j && bfs(e, start, id, count));
				}
			}
		dequeue(e);
	}
	return (0);
}
