/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:42:34 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/07 16:30:50 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_lst(t_env *e)
{
	t_room *tmp;

	tmp = e->room;
	while (tmp)
	{
		printf("room = %s\n", tmp->name);
		printf("id = %d\n", tmp->id);
		printf("ant = %d\n", tmp->ant);
		tmp = tmp->next;
	}
}

void		print_tab(void ***tab, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			printf("%-15p", tab[i][j]);
		printf("\n");
	}
}
