/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:50:43 by agissing          #+#    #+#             */
/*   Updated: 2019/02/10 20:41:43 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_tab(t_env *e)
{
	int		y;

	y = -1;
	while (++y < e->info.nb_room)
		free(e->tab[y]);
	free(e->tab);
}

void		frexit(void	*to_free, int error)
{
	free(to_free);
	ft_exit(error);
}

void			free_env(t_env *e)
{
	t_tube		*tmp;
	t_solve		*tmp1;
	t_way		*tmp2;
	t_room		*tmp3;

	tmp1 = e->solve;
	free_tab(e);
	while (e->tube)
	{
		tmp = e->tube;
		free(tmp->link);
		e->tube = e->tube->next;
		free(tmp);
	}
	free(e->tube);
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
	while (e->room)
	{
		tmp3 = e->room;
		free(e->room->name);
		e->room = e->room->next;
		free(tmp3);
	}
	free(e->info.start);
	free(e->info.end);
	free(e->info.comment);
}
