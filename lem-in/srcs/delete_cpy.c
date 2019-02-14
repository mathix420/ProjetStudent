/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:07:52 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/12 12:17:53 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		cpy_room(t_env *e, t_solve *new_solve, t_solve *ptr)
{
	t_way		*ptr_path;
	t_way		*cpy;
	t_way		*tmp;
	int			i;

	ptr_path = ptr->path->next;
	i = 0;
	while (ptr_path)
	{
		if (!(cpy = (t_way *)ft_memalloc(sizeof(t_way))))
			free_env(e, 2);
		if (!i++)
			new_solve->path = cpy;
		else
			tmp->next = cpy;
		cpy->room = ptr_path->room;
		cpy->round = ptr_path->round;
		tmp = cpy;
		ptr_path = ptr_path->next;
	}
}

t_solve			*cpy_path(t_env *e, t_solve *ptr)
{
	t_solve		*new_solve;
	t_solve		*tmp1;

	if (!(new_solve = (t_solve *)ft_memalloc(sizeof(t_solve))))
		free_env(e, 2);
	new_solve->nb = ptr->nb;
	cpy_room(e, new_solve, ptr);
	tmp1 = e->solve;
	while (tmp1->next)
		tmp1 = tmp1->next;
	new_solve->next = NULL;
	tmp1->next = new_solve;
	return (tmp1->next);
}

static t_solve	*first_node_delete(t_env *e, t_solve *ptr)
{
	t_solve		**tmp2;

	tmp2 = &e->solve;
	*tmp2 = ptr->next;
	free_way(ptr->path);
	free(ptr);
	return (*tmp2);
}

t_solve			*delete_path(t_env *e, t_solve *ptr)
{
	t_solve			*tmp;

	tmp = e->solve;
	if (tmp == ptr)
		return (first_node_delete(e, ptr));
	while (tmp->next)
	{
		if (tmp->next == ptr)
		{
			tmp->next = ptr->next;
			free_way(ptr->path);
			free(ptr);
			return (tmp->next);
		}
		tmp = tmp->next;
	}
	if (tmp == ptr)
	{
		tmp->next = ptr->next;
		free_way(ptr->path);
		free(ptr);
		return (tmp->next);
	}
	return (NULL);
}
