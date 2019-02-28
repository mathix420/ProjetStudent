/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:40:29 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 14:59:16 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_buff(t_env *e)
{
	t_buff	*tmp;

	tmp = e->buff;
	while (tmp)
	{
		write(1, tmp->str, tmp->i);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

static int		new_buff_node(t_env *e)
{
	t_buff	*new;
	t_buff	*ptr;

	ptr = e->buff;
	if (!(new = (t_buff *)ft_memalloc(sizeof(t_buff))))
		return (0);
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->next = NULL;
	e->buff = new;
	return (1);
}

static int		create_first_buff(t_env *e)
{
	t_buff	*first;

	if (!(first = (t_buff *)ft_memalloc(sizeof(t_buff))))
		return (0);
	e->buff = first;
	e->buff->next = NULL;
	return (1);
}

int				keep_map_in_buff(t_env *e, char *line)
{
	int		j;
	t_buff	*tmp;

	j = -1;
	if (!e->buff)
		if (!(create_first_buff(e)))
			return (0);
	tmp = e->buff;
	while (e->buff->next)
		e->buff = e->buff->next;
	while (line[++j])
	{
		if (e->buff->i == 5000)
			if (!(new_buff_node(e)))
				return (0);
		e->buff->str[e->buff->i++] = line[j];
	}
	if (e->buff->i == 5000)
		if (!(new_buff_node(e)))
			return (0);
	e->buff->str[e->buff->i++] = '\n';
	e->buff = tmp;
	return (1);
}
