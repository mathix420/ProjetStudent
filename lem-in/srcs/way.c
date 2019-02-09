/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:31:25 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/09 18:25:20 by agissing         ###   ########.fr       */
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

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		return ;
	way->room = addr;
	way->round = 0;
	way->next = NULL;
	if (!(tmp = (t_solve *)malloc(sizeof(t_solve))))
		return ;
	tmp->path = way;
	tmp->nb = way->room->id;
	tmp->next = e->solve;
	e->solve = tmp;
}

int				list_path(t_room *ptr, t_solve *tmp)
{
	t_way	*new;
	t_way	*test;

	test = tmp->path;
	if (test->room->id == 4)
		return (0);
	while (test)
	{
		if (test->room == ptr)
			return (0);
		test = test->next;
	}
	if (!(new = (t_way *)malloc(sizeof(t_way))))
		return (0);
	new->room = ptr;
	new->next = tmp->path;
	new->round = tmp->path->round + 1;
	tmp->path = new;
	tmp->nb = ptr->id;
	return (1);
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
	t_solve		*ptr_solve;
	t_solve		*tmp1;
	int			i;

	i = 0;
	ptr_path = ptr->path->next;
	if (!(ptr_solve = (t_solve *)malloc(sizeof(t_solve))))
		return (NULL);
	ptr_solve->nb = ptr->nb;
	while (ptr_path)
	{
		if (!(cpy = (t_way *)malloc(sizeof(t_way))))
			return (NULL);
		if (!i++)
			ptr_solve->path = cpy;
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
	ptr_solve->next = NULL;
	tmp1->next = ptr_solve;
	return (tmp1->next);
}

void        delete(t_env *e, t_solve *ptr)
{
    t_solve        *tmp;

    tmp = e->solve;
    while (tmp)
    {
        if (tmp->next->nb == ptr->nb || tmp == ptr)
        {
            tmp->next = ptr->next;
            free(ptr);
            break ;
        }
        tmp = tmp->next;
    }
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

	if (!(new = (t_way *)malloc(sizeof(t_way))))
		return ;
	new->room = ptr;
	new->next = tmp->path;
	new->round = tmp->path->round + 1;
	tmp->nb = ptr->id;
	tmp->path = new;
}

void		get_next(t_env *e, t_solve *group)
{
	int		x;
	int		y;
	int		first;
	t_solve	*tmp;
	
	x = -1;
	first = 1;
	y = group->nb;
	while (++x < e->info.nb_room)
	{
		if (e->tab[y][x] && !in_path(group->path, e->tab[y][x]))
		{
			if (first && first--)
				add_room(e->tab[y][x], group);
			else if ((tmp = cpy(e, group)))
				add_room(e->tab[y][x], tmp);
		}
	}
}

void		find_path(t_env *e)
{
	t_solve	*tmp;

	create_lst(e, e->room);
	tmp = e->solve;
	while (tmp)
	{
		while (!check_state(e, tmp))
			get_next(e, tmp);
		tmp = tmp->next;
	}
	print_way(e);
}
