/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/20 20:27:21 by agissing         ###   ########.fr       */
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
	get_childs(*tab->names, tab->opt);
	if (tab->opt & OPT_L)
		list_print(*(*tab->names)->child, tab->opt);
	else
		simple_print(*(*tab->names)->child, tab->opt);
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
	ls(&tab);
	return (0);
}
