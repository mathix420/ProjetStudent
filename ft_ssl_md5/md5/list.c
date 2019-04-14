/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:20:14 by agissing          #+#    #+#             */
/*   Updated: 2019/04/14 17:30:15 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl_md5.h"

void		copy_text(char out[6400], char *in, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		out[i++] = *in;
		in++;
	}
}

void		push_text(t_list **list, char str[6400], int count)
{
	t_list		*tmp;

	tmp = *list;
	if (!tmp)
	{
		e_error(!(*list = malloc(sizeof(t_list))), 0);
		(*list)->next = NULL;
		(*list)->size = count;
		copy_text((*list)->str, str, count);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		e_error(!(tmp->next = malloc(sizeof(t_list))), 0);
		tmp->next->next = NULL;
		tmp->next->size = count;
		copy_text(tmp->next->str, str, count);
	}
}

void		free_text(t_list *list)
{
	t_list		*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
