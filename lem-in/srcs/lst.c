/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:35:06 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/19 14:21:56 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				tube_lst(t_env *e, char *line)
{
	t_tube *new;

	if (!(new = (t_tube *)ft_memalloc(sizeof(t_tube))))
		return (0);
	new->link = ft_strdup(line);
	new->next = e->tube;
	e->tube = new;
	return (1);
}

static t_room	*room_check(t_env *e, char *line)
{
	t_room	*tmp;
	int		i;
	int		j;

	tmp = e->room;
	i = 0;
	if (!e->room)
		return (NULL);
	while (line[i] && line[i] != ' ')
		i++;
	while (tmp)
	{
		j = 0;
		while (tmp->name[j] && tmp->name[j] != ' ')	
			j++;
		if (i == j && !ft_strncmp(tmp->name, line, i))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				room_lst(t_env *e, char *line)
{
	t_room	*new;
	t_room	*tmp;

	if (e->info.nb_link)
		return (0);
	if ((tmp = room_check(e, line)))
	{
		tmp->name = ft_strdup(line);
		return (1);
	}
	e->info.nb_room++;
	if (!(new = (t_room *)ft_memalloc(sizeof(t_room))))
	{
		printf("ICI3\n");
		free_env(e, 1);
	}
	new->name = ft_strdup(line);
	new->next = e->room;
	e->room = new;
	return (1);
}
