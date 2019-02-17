/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:42:34 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/17 14:23:12 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
void		print_way(t_env *e)
{
	t_solve		*tmp1;
	t_way		*tmp2;

	tmp1 = e->solve;
	while (tmp1)
	{
		printf("=== NEW WAY ===\n");
		tmp2 = tmp1->path;
		printf("ADDR = %p\n", tmp1);
		printf("tmp1->id = %d\n", tmp1->id);
		printf("nb_ant = %d\n", tmp1->nb_ant);
		printf("e->solve->path->round = %d\n", tmp1->path->round);
		while (tmp2)
		{
			if (tmp2->room)
				printf("way->room = %s\n", tmp2->room->name);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void		print_round(t_env *e)
{
	t_round		*tmp1;

	tmp1 = e->round;
	while (tmp1)
	{
		printf("id = %d\n", tmp1->solve->id);
		printf("nb_ant = %d\n", tmp1->solve->nb_ant);
		printf("steps = %d\n", tmp1->solve->path->round + tmp1->solve->nb_ant - 1);
		printf("round = %d\n\n", tmp1->solve->path->round);
		tmp1 = tmp1->next;
	}
}

void		print_lst(t_env *e)
{
	t_room *tmp;

	tmp = e->room;
	while (tmp)
	{
		printf("ADDR = %p\n", tmp);
		printf("room = %s\n", tmp->name);
		printf("id = %d\n", tmp->id);
		printf("ant = %d\n", tmp->ant);
		tmp = tmp->next;
	}
}

void		print_tab2(void ***tab, int size)
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

void		print_tab(void ***tab, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size && !tab[j][i])
			j++;
		if (j < size && tab[j][i])
			printf("%c : ", ((t_room *)tab[j][i])->name[0]);
		j = -1;
		while (++j < size)
			if (tab[i][j])
				printf("%-2c", ((t_room *)tab[i][j])->name[0]);
		printf("\n");
	}
}
*/
