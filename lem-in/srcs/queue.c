/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:26:03 by agissing          #+#    #+#             */
/*   Updated: 2019/02/27 14:41:26 by acompagn         ###   ########.fr       */
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

void					clear_queue(t_env *e)
{
	while (e->queue)
		dequeue(e);
}

int						enqueue(t_env *e, t_node *elmt)
{
	t_queue		*tmp;

	if (!e->queue && (e->queue = create_new(elmt)))
		e->end_queue = e->queue;
	else if (!e->queue || !(tmp = create_new(elmt)))
		return (0);
	else
	{
		e->end_queue->next = tmp;
		e->end_queue = tmp;
	}
	return (1);
}

void					dequeue(t_env *e)
{
	t_queue		*first;

	first = e->queue;
	e->queue = e->queue->next;
	if (first == e->end_queue)
		e->end_queue = NULL;
	free(first);
}
