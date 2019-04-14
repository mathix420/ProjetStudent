/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:49:50 by agissing          #+#    #+#             */
/*   Updated: 2019/04/14 18:29:08 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ssl_md5.h"
#include <fcntl.h>

void		pt(t_list *lst)
{
	while (lst)
	{
		write(1, lst->str, lst->size);
		lst = lst->next;
	}
}

int			bit_len(t_list list)
{
	int		i;

	i = 0;
	while (list.next)
	{
		list = *list.next;
		i++;
	}
	i = i * 6400 + list.size;
	return (i);
}

void		padding(t_list *list)
{
	char	pad;
	int		size;

	pad = 0x80;
	size = bit_len(*list);
	while (list->next)
		list = list->next;
	while (size++ % 64 != 56 || pad)
	{
		if (list->size + 1 >= 6400)
		{
			push_text(&list, &pad, 1);
			list = list->next;
		}
		else
			list->str[list->size++] = pad;
		pad = 0;
	}
}

void		readfile(int fp, t_list **lst)
{
	char	tmp[6400];
	int		count;

	tmp[0] = 0;
	while ((count = read(fp, tmp, 6400)))
		push_text(lst, tmp, count);
	padding(*lst);
	printf("%d\n", bit_len(**lst) / 4);
}

void		md5(t_env *env)
{
	t_list	**lst;
	int		fp;

	fp = 0;
	e_error(!(lst = malloc(sizeof(t_list *))), 0);
	*lst = NULL;
	if (env->argc >= 3)
		e_error((fp = open(env->opt, O_RDONLY)), 0);
	readfile(fp, lst);
	close(fp);
}
