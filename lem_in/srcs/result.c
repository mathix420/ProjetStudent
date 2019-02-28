/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:35:07 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/28 16:36:38 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_id(t_env *e, int nb_ant)
{
	int		i;

	i = -1;
	while (++i < e->room->node->nb_next)
		if (e->tab_id[i] == nb_ant)
			return (i);
	return (-1);
}

static void		print_one_round2(t_env *e, t_room **room, int *passed, int id)
{
	if (id >= 0 && (*room)->depth == 2 && e->tab_ant[id])
	{
		(*room)->old_ant = ((*room)->lock) ? (*room)->lock : (*room)->old_ant;
		(*room)->lock = *passed;
		listing_res(e, *passed, (*room)->name, (*room)->id);
		*passed += 1;
		e->tab_ant[id]--;
	}
	else if (id >= 0 && (*room)->depth == 2
			&& ((*room)->old_ant = (*room)->lock))
		(*room)->lock = 0;
	else if ((*room)->nb_ant == e->queue->node->room->nb_ant
			|| (*room)->id == e->info.end_id)
	{
		(*room)->old_ant = (*room)->lock;
		(*room)->lock = e->queue->node->room->old_ant;
		if ((*room)->lock)
			listing_res(e, (*room)->lock, (*room)->name, (*room)->id);
		if ((*room)->lock && (*room)->id == e->info.end_id)
		{
			e->info.nb_ant--;
			e->queue->node->room->old_ant = 0;
		}
	}
}

static void		print_one_round(t_env *e, t_node *start, int *passed)
{
	int		i;
	t_room	*room;

	(!(enqueue(e, start))) ? free_env(e, 3) : 1;
	start->room->depth = 1;
	while (e->queue)
	{
		i = -1;
		while (++i < e->queue->node->nb_next)
		{
			room = e->queue->node->next[i]->room;
			if ((!room->depth && room->nb_ant) || room->id == e->info.end_id)
			{
				room->depth = e->queue->node->room->depth + 1;
				print_one_round2(e, &room, passed, get_id(e, room->nb_ant));
				if (room->id != e->info.end_id
				&& (e->queue->node->room->nb_ant == room->nb_ant
				|| e->queue->node->room->id == e->info.start_id))
					(!(enqueue(e, room->node))) ? free_env(e, 3) : 1;
				else
					room->depth = 0;
			}
		}
		dequeue(e);
	}
}

void			print_solution(t_env *e)
{
	int		nb_paths;
	int		passed;

	passed = 1;
	nb_paths = clean_count(e);
	clear_queue(e);
	while (e->info.nb_ant)
	{
		clean_depth(e);
		print_one_round(e, e->room->node, &passed);
		print_result_list(e);
		clear_queue(e);
	}
}
