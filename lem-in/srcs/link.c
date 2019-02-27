/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:32:19 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 14:43:57 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	start_end_link(t_env *e, t_room *end)
{
	char	*char_ant;
	int		ant;
	int		i;

	ant = 0;
	while (++ant <= e->info.nb_ant)
	{
		i = -1;
		write(1, "L", 1);
		if (!(char_ant = ft_itoa(ant)))
			break ;
		while (char_ant[++i])
			write(1, &char_ant[i], 1);
		free(char_ant);
		write(1, "-", 1);
		i = -1;
		while (end->name[++i])
			write(1, &end->name[i], 1);
		(ant != e->info.nb_ant) ? write(1, " ", 1) : write(1, "\n", 1);
	}
	free_env(e, 3);
}

static int	fill_links_tab(t_env *e, t_room **addr1, t_room **addr2)
{
	if (!*addr1 || !*addr2)
		return (0);
	if (((*addr1)->id == e->info.start_id || (*addr1)->id == e->info.end_id)
		&& ((*addr2)->id == e->info.start_id || (*addr2)->id == e->info.end_id))
	{
		cut_room_name(e);
		print_buff(e);
		start_end_link(e, ((*addr1)->id == e->info.end_id) ? *addr1 : *addr2);
	}
	e->info.nb_link++;
	e->tab[(*addr1)->id][(*addr2)->id] = *addr2;
	e->tab[(*addr2)->id][(*addr1)->id] = *addr1;
	*addr1 = NULL;
	*addr2 = NULL;
	return (1);
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
			if (!ft_strncmp(&t2->link[i[0] + 1], t1->name, i[1])
				&& t1->name[i[1]] == ' ')
				addr2 = t1;
			t1 = t1->next;
		}
		if (!(fill_links_tab(e, &addr1, &addr2)))
			return ;
		t2 = t2->next;
	}
}

int			create_link_tab(t_env *e)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	size = e->info.nb_room;
	if (!(e->tab = (t_room ***)ft_memalloc(sizeof(t_room **) * size)))
		return (0);
	while (++i < size)
	{
		j = -1;
		if ((!(e->tab[i] = (t_room **)ft_memalloc(sizeof(t_room *) * size))))
		{
			while (i--)
				free(e->tab[i]);
			free(e->tab);
			return (0);
		}
		while (++j < size)
			e->tab[i][j] = NULL;
	}
	find_links(e, NULL, NULL);
	return (1);
}
