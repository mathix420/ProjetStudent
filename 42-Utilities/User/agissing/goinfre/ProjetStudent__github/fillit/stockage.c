/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:08:56 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 17:10:16 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_cont		*ft_create_node(t_cont **start)
{
	t_cont		*container;
	t_cont		*tmp;

	if (!(container = (t_cont *)malloc(sizeof(t_cont))))
		ft_error();
	container->tetri = 0;
	container->x = 0;
	container->y = 0;
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
	return (container);
}
