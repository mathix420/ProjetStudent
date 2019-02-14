/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:50:43 by agissing          #+#    #+#             */
/*   Updated: 2019/02/11 13:07:43 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_way(t_way *to_free)
{
	t_way			*tmp_w;

	while (to_free)
	{
		tmp_w = to_free;
		to_free = to_free->next;
		free(tmp_w);
	}
}

static void		free_tab(t_env *e)
{
	int		y;

	y = -1;
	while (++y < e->info.nb_room)
		free(e->tab[y]);
	free(e->tab);
}

static void		free_tube_lst(t_env *e)
{
	t_tube	*tmp;

	while (e->tube)
	{
		tmp = e->tube;
		free(tmp->link);
		e->tube = e->tube->next;
		free(tmp);
	}
}

static void		free_room_lst(t_env *e)
{
	t_room		*tmp;

	while (e->room)
	{
		tmp = e->room;
		free(e->room->name);
		e->room = e->room->next;
		free(tmp);
	}
}

void			free_env(t_env *e, int error)
{
	t_solve		*tmp1;
	t_way		*tmp2;

	(error != 1) ? free_tab(e) : 1;
	free_tube_lst(e);
	while (e->solve)
	{
		while (e->solve->path)
		{
			tmp2 = e->solve->path;
			e->solve->path = e->solve->path->next;
			free(tmp2);
		}
		tmp1 = e->solve;
		e->solve = e->solve->next;
		free(tmp1);
	}
	free_room_lst(e);
	free(e->info.start);
	free(e->info.end);
	free(e->info.comment);
	if (error)
		ft_exit(0);
}
