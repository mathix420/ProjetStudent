/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:26:03 by agissing          #+#    #+#             */
/*   Updated: 2019/02/17 13:56:19 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_queue	*create_new(t_node *elmt)
{
	t_queue		*new;

	if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	new->node = elmt;
	new->next = NULL;
	return (new);
}

int						enqueue(t_env *e, t_node *elmt)
{
	if (!e->queue && (e->queue = create_new(elmt))) // si queue n'existe pas et que le malloc fontionne
		e->end_queue = e->queue; // on met la valeur dans le end_queue
	else if (!e->queue || !(e->end_queue->next = create_new(elmt))) // si un des deux malloc a buggue 
		return (0);
	return (1);
}

t_node					*dequeue(t_env *e) // need to free return after use
{
	t_queue		*first;
	t_node		*node;

	first = e->queue;
	e->queue = e->queue->next;
	if (first == e->end_queue)
		e->end_queue = NULL;
	node = first->node;
	free(first);
	return (node);
}
