/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:26:03 by agissing          #+#    #+#             */
/*   Updated: 2019/02/17 15:26:54 by agissing         ###   ########.fr       */
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
	t_queue		*tmp;

	if (!e->queue && (e->queue = create_new(elmt))) // si queue n'existe pas et que le malloc fontionne
	{
		printf("OK!\n");
		e->end_queue = e->queue; // on met la valeur dans le end_queue
	}
	else if (!e->queue || !(tmp = create_new(elmt))) // si un des deux malloc a buggue 
		return (0);
	else
	{
		e->end_queue->next = tmp;
		e->end_queue =  tmp;
	}
	return (1);
}

void					dequeue(t_env *e) // need to free return after use
{
	t_queue		*first;

	first = e->queue;
	e->queue = e->queue->next;
	if (first == e->end_queue)
		e->end_queue = NULL;
	free(first);
}
