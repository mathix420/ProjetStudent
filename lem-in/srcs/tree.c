/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:13:02 by agissing          #+#    #+#             */
/*   Updated: 2019/02/17 14:14:22 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_node	*create_node(t_env *e, t_room *room)
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
	new->nb_next = nb_next;
	if (!(new->next = (t_node *)ft_memalloc(sizeof(t_node * ) * nb_next)))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

static void		get_childs(t_env *e, t_node node)
{
	t_node	*next;
	int		x;

	x = -1;
	next = node->next;
	while (++x < e->info.nb_room)
		if (e->tab[room->id][x])
		{
			if (e->tab[room->id][x]->node)
				next = e->tab[room->id][x]->node;
			else if (!(next = create_node(e, e->tab[room->id][x])) || !enqueue(e, next)) // WARNING NEED TO FREE AND EXIT THERE
				ft_putstr("BIG ERROR !!!!!!!!!!!!!!!");
			if (next->room->depth == -1)
				next->room->depth = node->room->depth + 1;
			next++;
		}
}

t_node			*init_tree(t_env *e)
{
	t_node	*top;

	e->room->depth = 0;
	if (!(top = create_node(e, e->room)) || !enqueue(e, top))
		return (NULL);
	build_tree(e);
	return (top);
}

void			build_tree(t_env *e)
{
	t_node		node;

	while (e->queue)
	{
		node = dequeue(e);
		get_childs(e, node);		
	}
}
