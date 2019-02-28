/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:59:52 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 14:43:47 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			clean_count(t_env *e)
{
	t_room	*tmp;
	int		max_id;

	tmp = e->room;
	max_id = 0;
	while (tmp)
	{
		tmp->lock = 0;
		if (tmp->nb_ant > max_id)
			max_id = tmp->nb_ant;
		tmp = tmp->next;
	}
	return (max_id);
}

void		clean_depth(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		tmp->depth = 0;
		tmp = tmp->next;
	}
}

void		clean_to_restart(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		tmp->lock = 0;
		tmp->nb_ant = 0;
		tmp = tmp->next;
	}
	e->solve_id = 0;
	e->count = 0;
}

void		clean_ant(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		if (tmp->nb_ant != 1 && !tmp->lock)
			tmp->nb_ant = 0;
		tmp = tmp->next;
	}
}

void		clean_unused_path(t_env *e)
{
	t_room	*tmp;
	int		i;

	i = -1;
	while (++i < e->room->node->nb_next)
	{
		if (!e->tab_ant[i])
		{
			if (e->tab_id[i] && (tmp = e->room))
			{
				while (tmp)
				{
					if (tmp->id == e->tab_id[i])
					{
						tmp->lock = 0;
						tmp->nb_ant = 0;
					}
					tmp = tmp->next;
				}
			}
			e->tab_id[i] = 0;
			e->tab_size[i] = 0;
		}
	}
	e->steps = -1;
}
