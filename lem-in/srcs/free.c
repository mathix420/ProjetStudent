/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:50:43 by agissing          #+#    #+#             */
/*   Updated: 2019/02/27 14:45:57 by acompagn         ###   ########.fr       */
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

static void		free_tube_room(t_env *e)
{
	t_tube	*tmp1;
	t_room	*tmp2;

	while (e->tube)
	{
		tmp1 = e->tube;
		free(tmp1->link);
		e->tube = e->tube->next;
		free(tmp1);
	}
	while (e->room)
	{
		tmp2 = e->room;
		if (tmp2->node)
			free(tmp2->node->next);
		free(tmp2->node);
		free(tmp2->name);
		e->room = e->room->next;
		free(tmp2);
	}
}

static void		free_buff_res(t_env *e)
{
	t_buff		*tmp1;
	t_result	*tmp2;

	while (e->buff)
	{
		tmp1 = e->buff;
		e->buff = e->buff->next;
		free(tmp1);
	}
	while (e->res)
	{
		tmp2 = e->res;
		free(e->res->id);
		e->res = e->res->next;
		free(tmp2);
	}
}

void			free_env(t_env *e, int error)
{
	(error != 1) ? free_tab(e) : 1;
	if (e->tab_size)
		free(e->tab_size);
	if (e->tab_ant)
		free(e->tab_ant);
	if (e->tab_id)
		free(e->tab_id);
	free_tube_room(e);
	free_buff_res(e);
	free(e->info.start);
	free(e->info.end);
	free(e->info.comment);
	(error) ? ft_exit(error) : 1;
}
