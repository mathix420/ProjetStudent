/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:08:56 by agissing          #+#    #+#             */
/*   Updated: 2018/11/24 14:23:06 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_create_node(t_cont **start, int *x, int *y)
{
	t_cont		*container;
	t_cont		*tmp;

	if (!(container = (t_cont *)malloc(sizeof(t_cont))))
		ft_free_error(&tetri);
	container->x = x;
	container->y = y;
	container->next = NULL;
	if (!(*start))
		*start = container;
	else
	{
		tmp = (*start);
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = container;
	}
}

/* ------------------------------------------------ */
void		ft_print_list(t_cont *list)
{
	t_cont	*tmp;

	tmp = list;
	while (tmp && tmp->next)
	{
		printf("%s\n", tmp->tetri);
		tmp = tmp->next;
	}
	if (tmp)
		printf("%s\n", tmp->tetri);
}
/* ------------------------------------------------ */
