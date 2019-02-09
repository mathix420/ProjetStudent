/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:21:45 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/07 17:38:41 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_lst(t_env *e)
{
	e->error = 0;
	e->room = NULL;
	e->tube = NULL;
	e->solve = NULL;
	e->info.nb_ant = 0;
	e->info.nb_room = 0;
	e->info.nb_link = 0;
	e->info.comment = NULL;
	e->info.is_start = 0;
	e->info.is_end = 0;
	e->info.start = NULL;
	e->info.end = NULL;
}

void			init_id(t_room *room)
{
	t_room	*tmp;
	int		i;

	tmp = room;
	i = 0;
	while (tmp)
	{
		tmp->id = i;
		tmp->ant = 0;
		tmp = tmp->next;
		i++;
	}
}
