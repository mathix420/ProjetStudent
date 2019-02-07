/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:03:48 by agissing          #+#    #+#             */
/*   Updated: 2019/02/07 21:58:14 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls(t_struct *tab)
{
	t_param		*tmp;

	get_childs(*tab->names, tab->opt);
	if (((tmp = *tab->names) || 1) && tab->opt & OPT_LR)
		reverse_param(tab->names);
	while (tmp)
	{
		if (tmp->ok)
		{
			if ((*tab->names)->next && !tab->nb)
				ft_addtwostr(&tab->bf, (tmp)->name, ":\n");
			else if (tab->nb)
			{
				ft_addchar(&tab->bf, '\n');
				ft_addtwostr(&tab->bf, (tmp)->name, ":\n");
			}
			if (tab->opt & OPT_L)
				list_print(*(tmp)->child, tab->opt, &tab->bf);
			else
				simple_print(*(tmp)->child, &tab->bf, tab->opt);
			tab->nb++;
		}
		tmp = (tmp)->next;
	}
	ft_putbuff(&tab->bf);
}

int		is_p_pp(char *name)
{
	return ((name[0] == '.' && !name[1])
			|| (name[0] == '.' && name[1] && name[1] == '.' && !name[2]));
}

void	ls_rec(t_struct *tab)
{
	t_struct	new;
	t_param		*tmp;
	t_lst		*tmp1;

	tmp = *tab->names;
	ls(tab);
	new.opt = tab->opt;
	new.nb = tab->nb;
	new.bf = tab->bf;
	while ((*tab->names))
	{
		if (!(new.names = (t_param **)malloc(sizeof(t_param *))))
			return ;
		ft_sort((*tab->names)->child, tab->opt);
		if (!(*new.names = NULL) && tab->opt & OPT_LR)
			reverse_lst((*tab->names)->child);
		while (*(*tab->names)->child)
		{
			if (S_ISDIR((*(*tab->names)->child)->stat.st_mode)
				&& !is_p_pp(ft_title((*(*tab->names)->child)->name, 0)))
			{
				ft_param_push_back(new.names, (*(*tab->names)->child)->name);
				ls_rec(&new);
			}
			tmp1 = *((*tab->names))->child;
			*((*tab->names))->child = (*(*tab->names)->child)->next;
			free(tmp1->name);
			free(tmp1);
		}
		(*tab->names) = ((*tab->names))->next;
	}
	free(new.names);
	ft_free(tab->names);
	ft_free(&tmp);
}

int		link_pointer(t_buf *i, char *name)
{
	char	*buf;

	buf = ft_strnew(500);
	ft_addstr(i, " -> ");
	readlink(name, buf, 500);
	ft_addstr(i, buf);
	free(buf);
	return (1);
}
