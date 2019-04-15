/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:49:50 by agissing          #+#    #+#             */
/*   Updated: 2019/04/15 17:43:54 by agissing         ###   ########.fr       */
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

uint64_t	bit_len(t_list list)
{
	uint64_t	i;

	i = 0;
	while (list.next)
	{
		list = *list.next;
		i++;
	}
	i = i * BUF_SIZE + list.size;
	return (i);
}

void		padding(t_list *list)
{
	char		pad;
	char		*sav;
	uint64_t	size;

	pad = 0x80;
	size = bit_len(*list);
	sav = (char *)size;
	while (list->next)
		list = list->next;
	while (size++ % 64 != 56 || pad)
	{
		if (list->size + 1 >= BUF_SIZE)
		{
			push_text(&list, &pad, 1);
			list = list->next;
		}
		else
			list->str[list->size++] = pad;
		pad = 0;
	}
	if (list->size + 8 >= BUF_SIZE)
	{
		push_text(&list, sav, 8);
		list = list->next;
	}
	while (pad++ < 8)
		list->str[list->size++] = (char)sav++;
}

void		make_str(t_env *env, t_list *list)
{
	uint64_t	count;

	count = 0;
	count = bit_len(*list);
	e_error(!(env->md5.data = malloc(count)), 0);
	env->md5.data[0] = 0;
	while (list)
	{
		ft_strcat(env->md5.data, list->str);
		list = list->next;
	}
}

void		md5(t_env *env)
{
	t_list	**lst;
	char	tmp[BUF_SIZE];
	int		count;
	int		fp;

	fp = 0;
	e_error(!(lst = malloc(sizeof(t_list *))), 0);
	*lst = NULL;
	if (env->argc >= 3)
		e_error((fp = open(env->opt, O_RDONLY)), 0);
	tmp[0] = 0;
	while ((count = read(fp, tmp, BUF_SIZE)))
		push_text(lst, tmp, count);
	close(fp);
//	do_the_work(*lst);
}
