/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:42:34 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 12:37:39 by agissing         ###   ########.fr       */
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
