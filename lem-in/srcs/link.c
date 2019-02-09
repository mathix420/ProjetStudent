/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:32:19 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/07 20:28:50 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	fill_links_tab(t_env *e, t_room *addr1, t_room *addr2)
{
	if (!addr1 || !addr2)
		return ;
	e->info.nb_link++;
	e->tab[addr1->id][addr2->id] = addr2;
	e->tab[addr2->id][addr1->id] = addr1;
}

static void	find_links(t_env *e, t_room *addr1, t_room *addr2)
{
	t_room	*t1;
	t_tube	*t2;
	int		i[2];

	t2 = e->tube;
	while (t2)
	{
		i[0] = 0;
		t1 = e->room;
		while (t2->link[i[0]] && t2->link[i[0]] != '-')
			i[0]++;
		while (t1)
		{
			if (!ft_strncmp(t2->link, t1->name, i[0]) && t1->name[i[0]] == ' ')
				addr1 = t1;
			i[1] = ft_strlen(t2->link) - i[0] - 1;
			if (!ft_strncmp(&t2->link[i[0] + 1], t1->name, i[1]))
				addr2 = t1;
			t1 = t1->next;
		}
		fill_links_tab(e, addr1, addr2);
		addr1 = NULL;
		addr2 = NULL;
		t2 = t2->next;
	}
}

int			create_link_tab(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	if (!(e->tab = (void ***)malloc(sizeof(void **) * e->info.nb_room)))
		return (0);
	while (++i < e->info.nb_room)
	{
		j = -1;
		if (!(e->tab[i] = (void **)malloc(sizeof(void *) * e->info.nb_room)))
		{
			while (i)
				free(e->tab[i--]);
			free(e->tab);
			return (0);
		}
		while (++j < e->info.nb_room)
			e->tab[i][j] = NULL;
	}
	find_links(e, NULL, NULL);
	return (1);
}
