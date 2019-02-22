/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:48:13 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/19 14:18:08 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*start_end_cmp(t_env *e, char *cmp)
{
	t_room	*tmp;
	t_room	*to_free;
	int		i;

	tmp = e->room;
	i = 0;
	while (cmp[i] && cmp[i] != ' ')
		i++;
	while (tmp && tmp->next)
	{
		if (!ft_strncmp(tmp->next->name, cmp, i))
		{
			to_free = tmp->next;
			tmp->next = tmp->next->next;
			free(to_free);
			e->info.nb_room--;
		}
		tmp = tmp->next;
	}
	return (tmp);
}

int				add_end(t_env *e)
{
	t_room	*new;
	t_room	*tmp;

	tmp = start_end_cmp(e, e->info.end);
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

	tmp = start_end_cmp(e, e->info.start);
	e->info.nb_room++;
	if (!(new = (t_room *)ft_memalloc(sizeof(t_room))))
		return (0);
	new->name = ft_strdup(e->info.start);
	new->next = e->room;
	e->room = new;
	return (1);
}
