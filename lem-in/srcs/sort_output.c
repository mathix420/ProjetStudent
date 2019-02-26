/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:09:04 by agissing          #+#    #+#             */
/*   Updated: 2019/02/16 17:53:23 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			sort_output(t_env *e)
{
	t_solve		*tmp;
	t_way		*tmp_path;
	int			nb_tmp;

	tmp = e->solve;
	while (tmp && tmp->next)
	{
		if (tmp->path->round > tmp->next->path->round)
		{
			tmp_path = tmp->next->path;
			nb_tmp = tmp->next->nb;
			tmp->next->path = tmp->path;
			tmp->next->nb = tmp->nb;
			tmp->path = tmp_path;
			tmp->nb = nb_tmp;
			tmp = e->solve;
		}
		else
			tmp = tmp->next;
	}
}

static inline int	is_end_start(t_env *e, t_room *room)
{
	return (room->id == e->info.start_id || room->id == e->info.end_id);
}

static int			linked(t_env *e, t_round *round, t_solve *cmp2)
{
	t_way	*way1;
	t_way	*way2;
	t_round	*tmp;

	tmp = round;
	while (tmp)
	{
		way1 = tmp->solve->path;
		while (way1)
		{
			way2 = cmp2->path;
			while (way2)
			{
				if (way1->room == way2->room && !is_end_start(e, way1->room))
				{
					(!round->solve->next) ? round->solve = NULL : NULL;
					return (1);
				}
				way2 = way2->next;
			}
			way1 = way1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static void				spread(t_round *round, int nb_ant)
{
	t_round		*tmp;
	t_round		*min;
	int			a;
	int			b;

	while (nb_ant)
	{
		tmp = round;
		min = round;
		while (tmp)
		{
			a = min->solve->path->round + min->solve->nb_ant;
			b = tmp->solve->path->round + tmp->solve->nb_ant;
			if (a > b)
				min = tmp;
			tmp = tmp->next;
		}
		min->solve->nb_ant++;
		min->steps++;
		nb_ant--;
	}
}

static void			add_to_round(int steps, t_round **round, t_solve *way)
{
	t_round	*new;

	if (!(new = (t_round *)ft_memalloc(sizeof(t_round))))
		return ;
	new->solve = way;
	new->steps = steps;
	new->next = *round;
	new->nb_paths = (*round)->nb_paths + 1;
	*round = new;
}

void				path_to_round(t_env *e, t_round *round, t_solve *way)
{
	int		step1;
	int		step2;
	int		nb_ant_in_1;
	int		nb_ant_in_2;
	int		old_gap;
	int		start;

	nb_ant_in_1 = e->info.nb_ant - 1;
	nb_ant_in_2 = 1;
	step1 = round->steps - 1;
	step2 = way->path->round;
	old_gap = 0;
	start = 0;
	while ((old_gap > (step2 - step1 < 0 ? step1 - step2 : step2 - step1) || !start) && nb_ant_in_1 > 0)
	{
		old_gap = step2 - step1;
		old_gap = old_gap < 0 ? -old_gap : old_gap;
		step1--;
		nb_ant_in_1--;
		step2++;
		nb_ant_in_2++;
		start = 1;
	}	
	if (old_gap < (step2 - step1 < 0 ? step1 - step2 : step2 - step1))
	{
		step1++;
		nb_ant_in_1++;
		step2--;
		nb_ant_in_2--;
	}
	if (step2 <= round->steps)
		add_to_round(step2, &e->round, way);
}

static void			find_round(t_env *e, t_solve *ptr)
{
	t_solve		*tmp;

	tmp = ptr;
	while (tmp)
	{
		if (!e->round->solve)
		{
			e->round->solve = tmp;
			e->round->steps = tmp->path->round + e->info.nb_ant - 1;
			e->round->nb_paths = 1;
			tmp = e->solve;
		}
		if (!linked(e, e->round, tmp))
			path_to_round(e, e->round, tmp);
		tmp = tmp->next;
	}
}

void				init_resolution(t_env *e)
{
	t_solve		*tmp;
	t_round		*ptr_round;
	int			i;
	int			x;

	tmp = e->solve;
	i = -1;
	x = 0;
	sort_output(e);
	while (tmp)
	{
		tmp->id = x++;
		e->info.nb_path++;
		tmp = tmp->next;
	}
	!e->info.nb_path ? free_env(e, 2) : 1;
	tmp = e->solve;
	ptr_round = NULL;
	while (tmp && tmp->next)
	{
		if (!(e->round = (t_round *)ft_memalloc(sizeof(t_round))))
			return ;
		e->round->solve = NULL;
		e->round->next = NULL;
		find_round(e, tmp);
		if (!ptr_round || e->round->steps < ptr_round->steps)
		{
			ptr_round = e->round;
			e->round = NULL;
		}
		tmp = tmp->next;
	}
	e->round = ptr_round;
	spread(e->round, e->info.nb_ant);
	print_round(e);
}
