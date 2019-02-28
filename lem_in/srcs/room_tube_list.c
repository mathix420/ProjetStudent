/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_tube_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:10:21 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/28 18:51:31 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				tube_list(t_env *e, char *line)
{
	t_tube	*new;
	t_tube	*ptr;

	ptr = e->tube;
	if (!(new = (t_tube *)ft_memalloc(sizeof(t_tube))))
		return (0);
	if (!(new->link = ft_strdup(line)))
		return (0);
	new->next = NULL;
	if (!e->tube)
		e->tube = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
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

int				room_list(t_env *e, char *line)
{
	t_room	*new;
	t_room	*tmp;

	if (e->info.nb_link || !(check_coor(line)))
		return (0);
	if ((tmp = room_check(e, line)))
	{
		free(tmp->name);
		if (!(tmp->name = ft_strdup(line)))
			free_env(e, 1);
		return (1);
	}
	e->info.nb_room++;
	if (!(new = (t_room *)ft_memalloc(sizeof(t_room))))
		free_env(e, 1);
	if (!(new->name = ft_strdup(line)))
		free_env(e, 1);
	new->next = e->room;
	e->room = new;
	return (1);
}
