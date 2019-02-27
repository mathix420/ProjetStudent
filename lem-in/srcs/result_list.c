/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:52:10 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 14:38:46 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_result	*ant_in_list(t_env *e, int id_ant)
{
	t_result	*ptr;

	ptr = e->res;
	while (ptr && ptr->next)
	{
		if (ptr->int_id == id_ant)
			break ;
		ptr = ptr->next;
	}
	return (ptr);
}

void			print_result_list(t_env *e)
{
	t_result	*ptr;
	int			i;

	ptr = e->res;
	while (ptr)
	{
		if (!ptr->arrived)
		{
			i = -1;
			write(1, "L", 1);
			while (ptr->id[++i])
				write(1, &ptr->id[i], 1);
			write(1, "-", 1);
			i = -1;
			while (ptr->room[++i])
				write(1, &ptr->room[i], 1);
			(ptr->next) ? write(1, " ", 1) : 1;
			(!ptr->next) ? write(1, "\n", 1) : 1;
		}
		ptr->arrived = (ptr->room_id == e->info.end_id) ? 1 : 0;
		ptr = ptr->next;
	}
}

void			listing_res(t_env *e, int id_ant, char *room, int room_id)
{
	t_result	*ptr;
	t_result	*new;

	ptr = ant_in_list(e, id_ant);
	if (!e->res || ptr->int_id != id_ant)
	{
		if (!(new = (t_result *)ft_memalloc(sizeof(t_result))))
			return ;
		(!(new->id = ft_itoa(id_ant))) ? free_env(e, 3) : 1;
		new->int_id = id_ant;
		new->room = room;
		new->room_id = room_id;
		new->next = NULL;
		if (!e->res)
			e->res = new;
		else
			ptr->next = new;
	}
	else
	{
		ptr->room = room;
		ptr->room_id = room_id;
	}
}
