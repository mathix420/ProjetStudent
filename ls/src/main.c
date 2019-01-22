/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/22 18:29:43 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_file(char *name)
{
	DIR			*fd;

	if ((fd = opendir(name)) && closedir(fd))
		return (0);
	if (errno == ENOTDIR)
		return (1);
	return (-1);
}

void	ls(t_struct *tab)
{
	t_param		*tmp;

	get_childs(*tab->names, tab->opt);
	if (tab->opt & OPT_LR)
		reverse_param(tab->names);
	tmp = *tab->names;
	while (tmp)
	{
		if ((tmp)->next && tab->nb <= 1)
			printf("%s:\n", (tmp)->name);
		else if (tab->nb)
			printf("\n%s:\n", (tmp)->name);
		if (tab->opt & OPT_L)
			list_print(*(tmp)->child, tab->opt);
		else
			simple_print(*(tmp)->child, tab->opt);
		tab->nb++;
		tmp = (tmp)->next;
	}
}

void	ls_rec(t_struct *tab)
{
	t_struct	new;

	ls(tab);
	new.opt = tab->opt;
	new.nb = tab->nb;
	while (*tab->names)
	{
		if (!(new.names = (t_param **)malloc(sizeof(t_param *))))
			return ;
		*new.names = NULL;
		ft_sort((*tab->names)->child, tab->opt);
		if (tab->opt & OPT_LR)
			reverse_lst((*tab->names)->child);
		while (*(*tab->names)->child)
		{
			if (S_ISDIR((*(*tab->names)->child)->stat.st_mode))
			{
				ft_param_push_back(new.names, (*(*tab->names)->child)->name);
				ls_rec(&new);
			}
			*(*tab->names)->child = (*(*tab->names)->child)->next;
		}
		free(new.names);
		*tab->names = (*tab->names)->next;
	}
}

int		main(int ac, char **av)
{
	int			i;
	t_struct	tab;

	i = 1;
	tab.opt = 0;
	if (!(tab.names = (t_param **)malloc(sizeof(t_param *))))
		return (0);
	*tab.names = NULL;
	while (i < ac)
		if (av[i][0] == '-')
			options(av[i++], &tab);
		else if (av[i][0] != '-')
			ft_param_push_back(tab.names, av[i++]);
	if (!*tab.names)
		ft_param_push_back(tab.names, ".");
	tab.nb = (*tab.names)->next ? 1 : 0;
	tab.opt & OPT_UR ? ls_rec(&tab) : ls(&tab);
	return (0);
}
