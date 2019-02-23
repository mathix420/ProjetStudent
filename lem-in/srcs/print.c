/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:05:04 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/23 18:25:06 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_room(t_env *e, int lock_print)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		if (tmp->nb_ant)
		{
			if (lock_print && tmp->lock)
				printf("LOCKED => ");
			if (tmp->nb_ant)
				printf("%s ==== %d\n", tmp->name, tmp->nb_ant);
		}
		tmp = tmp->next;
	}
}

void		print_tab(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->room->node->nb_next)
		printf("%-4d", e->tab_size[i]);
	printf("\n");
	i = -1;
	while (++i < e->room->node->nb_next)
		printf("%-4d", e->tab_ant[i]);
	printf("\n");
	i = -1;
	while (++i < e->room->node->nb_next)
		printf("%-4d", e->tab_id[i]);
	printf("\n\n");
}

void		print_neighbours(t_env *e)
{
	t_room	*ptr;
	int		i;

	ptr = e->room;
	i = -1;
	printf("START ROOM ===== %s\n", e->room->name);
	while (++i < ptr->node->nb_next)
		printf("---> %s\n", ptr->node->next[i]->room->name);
	while (ptr->next)
		ptr = ptr->next;
	printf("\n\nEND ROOM ----> %s\n", ptr->name);
	i = -1;
	while (++i < ptr->node->nb_next)
		printf("---> %s\n", ptr->node->next[i]->room->name);
}

void		print_call(t_env *e, int best_call, int room_print, int lock_print)
{
	printf("BEST CALL FOR NOW ==== %d\n", best_call);
	printf("\n\n=========== CALL %d ==============\n", e->count + 1);
	printf("steps => %d\n", e->steps);
	print_tab(e);
	if (room_print)
	{
		printf(" -- ROOMS --\n\n");
		if (lock_print)
			print_room(e, 1);
		else
			print_room(e, 0);
	}
}

void		print_buff(t_env *e)
{
	t_buff	*tmp;

	tmp = e->buff;
	while (tmp)
	{
		write(1, tmp->str, ft_strlen(tmp->str));
		tmp = tmp->next;
	}
}
