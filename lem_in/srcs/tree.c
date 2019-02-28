/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:13:02 by agissing          #+#    #+#             */
/*   Updated: 2019/02/27 14:40:54 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_node		*create_node(t_env *e, t_room *room)
{
	t_node	*new;
	int		nb_next;
	int		x;

	x = -1;
	nb_next = 0;
	while (++x < e->info.nb_room)
		e->tab[room->id][x] ? nb_next++ : 0;
	if (!(new = (t_node *)ft_memalloc(sizeof(t_node)
									+ sizeof(t_node *) * nb_next)))
		return (NULL);
	new->room = room;
	room->node = new;
	new->nb_next = nb_next;
	if (!(new->next = (t_node **)ft_memalloc(sizeof(t_node *) * nb_next)))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static inline void	sort_next(t_node **next, int nb_next)
{
	t_node	*tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < nb_next)
	{
		j = -1;
		while (++j < nb_next)
		{
			if (next[i]->room->depth < next[j]->room->depth)
			{
				tmp = next[i];
				next[i] = next[j];
				next[j] = tmp;
			}
		}
	}
}

static void			get_nexts(t_env *e, t_node *node)
{
	t_node	**next;
	int		x;
	int		i;

	x = -1;
	i = 0;
	next = node->next;
	while (++x < e->info.nb_room)
		if (e->tab[node->room->id][x])
		{
			if (e->tab[node->room->id][x]->node)
				next[i] = e->tab[node->room->id][x]->node;
			else if (!(next[i] = create_node(e, e->tab[node->room->id][x]))
					|| !enqueue(e, next[i]))
				free_env(e, 3);
			if (next[i]->room->depth == -1)
				next[i]->room->depth = node->room->depth + 1;
			i++;
		}
	sort_next(node->next, node->nb_next);
}

static void			build_tree(t_env *e)
{
	while (e->queue)
	{
		get_nexts(e, e->queue->node);
		dequeue(e);
	}
}

t_node				*init_tree(t_env *e)
{
	t_node	*top;

	e->room->depth = 0;
	if (!(top = create_node(e, e->room)) || !enqueue(e, top))
		return (NULL);
	e->room->node = top;
	build_tree(e);
	return (top);
}
