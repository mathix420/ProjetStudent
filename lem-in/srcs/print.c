/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:05:04 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/22 18:09:31 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				print_room(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		if (tmp->nb_ant)
		{
			if (tmp->lock)
				printf("LOCKED => ");
			printf("%s ==== %d\n", tmp->name, tmp->nb_ant);
		}
		tmp = tmp->next;
	}
}

void				print_tab(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->room->node->nb_next)
		printf("%d  ", e->tab_size[i]);
	printf("\n");
	i = -1;
	while (++i < e->room->node->nb_next)
		printf("%d  ", e->tab_ant[i]);
	printf("\n\n");
}
