/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:31:25 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 19:15:43 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_way(t_env *e)
{
	t_solve		*tmp1;
	t_way		*tmp2;

	tmp1 = e->solve;
	while (tmp1)
	{
		printf("=== NEW WAY ===\n");
		tmp2 = tmp1->path;
		printf("tmp1->nb = %d\n", tmp1->nb);
		printf("e->solve->path->round = %d\n", tmp1->path->round);
		while (tmp2)
		{
			if (tmp2->room)
				printf("way->room = %s\n", tmp2->room->name);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void			create_lst(t_env *e, t_room *addr)
{
	t_solve		*tmp;
	t_way		*way;

	if (!(way = (t_way *)ft_memalloc(sizeof(t_way))))
		return ;
	way->room = addr;
	way->round = 0;
	way->next = NULL;
	if (!(tmp = (t_solve *)ft_memalloc(sizeof(t_solve))))
		return ;
	tmp->path = way;
	tmp->nb = way->room->id;
	tmp->next = e->solve;
	e->solve = tmp;
}

int				check_state(t_env *e, t_solve *tmp)
{
	int			size;
	int			i;

	size = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->nb == e->info.nb_room - 1)
			i++;
		size++;
		tmp = tmp->next;
	}
	if (i == size)
		return (1);
	else
		return (0);
}

t_solve			*cpy(t_env *e, t_solve *ptr)
{
	t_way		*ptr_path;
	t_way		*cpy;
	t_way		*tmp;
	t_solve		*new_solve;
	t_solve		*tmp1;
	int			i;

	i = 0;
	ptr_path = ptr->path->next;
	if (!(new_solve = (t_solve *)ft_memalloc(sizeof(t_solve))))
		return (NULL);
	new_solve->nb = ptr->nb;
	while (ptr_path)
	{
		if (!(cpy = (t_way *)ft_memalloc(sizeof(t_way))))
			return (NULL);
		if (!i++)
			new_solve->path = cpy;
		else
			tmp->next = cpy;
		cpy->room = ptr_path->room;
		cpy->round = ptr_path->round;
		tmp = cpy;
		ptr_path = ptr_path->next;
	}
	tmp1 = e->solve;
	while (tmp1->next)
		tmp1 = tmp1->next;
	new_solve->next = NULL;
	tmp1->next = new_solve;
	return (tmp1->next);
}

int			in_path(t_way *way, t_room *test)
{
	while (way)
	{
		if (test->id == way->room->id)
			return (1);
		way = way->next;
	}
	return (0);
}

void		add_room(t_room *ptr, t_solve *tmp)
{
	t_way	*new;

	if (!(new = (t_way *)ft_memalloc(sizeof(t_way))))
		return ;
	new->room = ptr;
	new->next = tmp->path;
	new->round = tmp->path->round + 1;
	tmp->nb = ptr->id;
	tmp->path = new;
}

int			get_next(t_env *e, t_solve *group)
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
				add_room(e->tab[y][x], group);
			else if ((tmp = cpy(e, group)))
				add_room(e->tab[y][x], tmp);
		}
	return (!first);
}

void		free_way(t_way *to_free)
{
	t_way			*tmp_w;

	while (to_free)
	{
		tmp_w = to_free;
		to_free = to_free->next;
		free(tmp_w);
	}
}

t_solve		*delete(t_env *e, t_solve *ptr)
{
	t_solve			*tmp;
	t_solve			**tmp2;

	tmp = e->solve;
	tmp2 = &e->solve;
	if (*tmp2 == ptr)
	{
		*tmp2 = ptr->next;
		free_way(ptr->path);
		free(ptr);
		return (*tmp2);
	}
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
	printf("%p == %p\n", ptr, tmp);
	if (tmp == ptr)
	{
		tmp->next = ptr->next;
		free_way(ptr->path);
		free(ptr);
		return (tmp->next);
	}
	printf("ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR\n");
	return (NULL);
}

void		find_path(t_env *e)
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
			tmp = delete(e, tmp);
		else
			tmp = tmp->next;
	}
	print_way(e);
}
