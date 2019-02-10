/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:35:06 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 20:48:37 by acompagn         ###   ########.fr       */
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

	tmp = e->room;
	i = 0;
	if (!e->room)
		return (NULL);
	while (line[i] && line[i] != ' ')
		i++;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, line, i))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int				add_end(t_env *e)
{
	t_room	*new;
	t_room	*tmp;
	t_room	*pouloulou;
	int		i;

	tmp = e->room;
	i = 0;
	while (e->info.end[i] && e->info.end[i] != ' ')
		i++;
	while (tmp->next)
	{
		if (!ft_strncmp(tmp->next->name, e->info.end, i))
		{
			pouloulou = tmp->next;
			tmp->next = tmp->next->next;
			free(pouloulou);
			e->info.nb_room--;
		}
		tmp = tmp->next;
	}
	e->info.nb_room++;
	if (!(new = (t_room *)ft_memalloc(sizeof(t_room))))
		return (0);
	new->name = ft_strdup(e->info.end);
	new->next = NULL;
	tmp->next = new;
	return (1);
}

int				add_start(t_env *e)
{
	t_room	*new;
	t_room	*tmp;
	t_room	*pouloulou;
	int		i;

	tmp = e->room;
	i = 0;
	while (e->info.start[i] && e->info.start[i] != ' ')
		i++;
	while (tmp->next)
	{
		if (!ft_strncmp(tmp->next->name, e->info.start, i))
		{
			pouloulou = tmp->next;
			tmp->next = tmp->next->next;
			free(pouloulou);
			e->info.nb_room--;
		}
		tmp = tmp->next;
	}
	e->info.nb_room++;
	if (!(new = (t_room *)ft_memalloc(sizeof(t_room))))
		return (0);
	new->name = ft_strdup(e->info.start);
	new->next = e->room;
	e->room = new;
	return (1);
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
		return (0);
	new->name = ft_strdup(line);
	new->next = e->room;
	e->room = new;
	return (1);
}
