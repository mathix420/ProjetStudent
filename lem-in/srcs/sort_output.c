/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:09:04 by agissing          #+#    #+#             */
/*   Updated: 2019/02/14 19:40:37 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			sort_output(t_env *e)
{
	t_solve		*tmp;
	t_way		*tmp_path;
	int			nb_tmp;

	tmp = e->solve;
	while (tmp->next)
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

static void				add_one_ant(t_round *round)
{
	t_round		*min;

	min = round;
	while (round)
	{
		if (min->steps > round->steps)
			min = round;
		round = round->next;
	}
	min->solve->nb_ant++;
	min->steps++;
}

static void				reset_ants(t_round *round)
{
	while (round)
	{
		round->solve->nb_ant = 0;
		round->steps = 0;
		round = round->next;
	}
}

void				path_to_round(t_env *e, t_round *round, t_solve *way)
{
	int		step1;
	int		step2;
	int		nb_ant_in_1;
	int		nb_ant_in_2;
	t_round	*tmp;

	nb_ant_in_1 = e->info.nb_ant - 1;
	nb_ant_in_2 = 1;
	step1 = round->steps - 1;
 	step2 = way->path->round;

/*debut de ;la fctim,*/
	int		old_gap;
	int		start;

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
/*fin de ;la fctim,*/
	if (step2 <= round->steps)
	{
		tmp = round;
		way->nb_ant = nb_ant_in_2;
		while (nb_ant_in_2 > 0)
		{
			if (tmp->next && tmp->solve->path->round > tmp->next->solve->path->round)
			{
				tmp->solve->nb_ant--;
				nb_ant_in_2--;
			}
			else if (tmp->next)
			{
				tmp->next->solve->nb_ant--;
				nb_ant_in_2--;
			}
			if (!tmp->next)
				tmp = round;
			else
				tmp = tmp->next;
		}
		add_to_round(step2, &e->round, way);
	}
}

static void			find_round(t_env *e)
{
	t_solve		*tmp;
	int			i;

	tmp = e->solve;
	while (tmp && tmp->next)
	{
		if (!e->round->solve)
		{
			e->round->solve = tmp;
			e->round->solve->nb_ant = e->info.nb_ant;
			e->round->steps = tmp->path->round + e->info.nb_ant - 1;
			e->round->nb_paths = 1;
		}
		if (!linked(e, e->round, tmp->next))
			path_to_round(e, e->round, tmp->next);
		tmp = tmp->next;
	}
	i = e->info.nb_ant;
	reset_ants(e->round);
	while (i--)
		add_one_ant(e->round);
}

void				init_resolution(t_env *e)
{
	t_solve		*tmp;
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
	if (!(e->round = (t_round *)ft_memalloc(sizeof(t_round))))
		return ;
	e->round->solve = NULL;
	e->round->next = NULL;
	find_round(e);
	print_round(e);
}
