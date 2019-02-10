/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:21:45 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 20:04:01 by acompagn         ###   ########.fr       */
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
	e->info.comment = ft_strnew(0);
	e->info.start_id = -1;
	e->info.end_id = -1;
	e->info.start = ft_strnew(0);
	e->info.end = ft_strnew(0);
}

void			init_id(t_env *e)
{
	t_room	*tmp;
	int		i;

	tmp = e->room;
	i = 0;
	e->info.start_id = 0;
	while (tmp)
	{
		tmp->id = i;
		tmp->ant = 0;
		tmp = tmp->next;
		i++;
	}
	e->info.end_id = i - 1;
}
