/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:31:25 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/16 15:03:48 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		create_lst(t_env *e, t_room *addr)
{
	t_solve		*tmp;
	t_way		*way;

	if (!(way = (t_way *)ft_memalloc(sizeof(t_way))))
		free_env(e, 2);
	way->room = addr;
	way->round = 0;
	way->next = NULL;
	if (!(tmp = (t_solve *)ft_memalloc(sizeof(t_solve))))
		free_env(e, 2);
	tmp->path = way;
	tmp->nb = way->room->id;
	tmp->next = e->solve;
	e->solve = tmp;
}

static int		in_path(t_way *way, t_room *test)
{
	while (way)
	{
		if (test->id == way->room->id)
			return (1);
		way = way->next;
	}
	return (0);
}

static void		add_room(t_env *e, t_room *ptr, t_solve *tmp)
{
	t_way	*new;

	if (!(new = (t_way *)ft_memalloc(sizeof(t_way))))
		free_env(e, 2);
	new->room = ptr;
	new->next = tmp->path;
	new->round = tmp->path->round + 1;
	tmp->nb = ptr->id;
	tmp->path = new;
}

static int		get_next(t_env *e, t_solve *group)
{
	int		x;
	int		y;
	int		first;
	t_solve	*tmp;

	x = -1;
	first = 1;
	y = group->nb;
	if (y == e->info.end_id)
		return (0);
	while (++x < e->info.nb_room)
		if (e->tab[y][x] && !in_path(group->path, e->tab[y][x]))
		{
			if (first && first--)
				add_room(e, e->tab[y][x], group);
			else if ((tmp = cpy_path(e, group)))
				add_room(e, e->tab[y][x], tmp);
		}
	return (!first);
}

void			find_path(t_env *e)
{
	int		i;
	t_solve	*tmp;

	create_lst(e, e->room);
	tmp = e->solve;
	while (tmp)
	{
		i = 1;
		while (i)
			i = get_next(e, tmp);
		if (!i && tmp->nb != e->info.end_id)
			tmp = delete_path(e, tmp);
		else
			tmp = tmp->next;
	}
}
