/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:50:43 by agissing          #+#    #+#             */
/*   Updated: 2019/02/23 14:28:24 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		if (tmp->node)
			free(tmp->node->next);
		free(tmp->node);
		free(tmp->name);
		e->room = e->room->next;
		free(tmp);
	}
}

void			free_env(t_env *e, int error)
{
	(error != 1) ? free_tab(e) : 1;
	free(e->tab_size);
	free(e->tab_ant);
	free_tube_lst(e);
	free_room_lst(e);
	free(e->info.start);
	free(e->info.end);
	free(e->info.comment);
	if (error)
		ft_exit(0);
}
