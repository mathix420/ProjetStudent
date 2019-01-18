/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/18 16:23:04 by agissing         ###   ########.fr       */
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

void	wich_ls(t_struct *tab)
{
	if ((tab->opt & OPT_A) && (tab->opt & OPT_L))
		ls_opt_la(tab);
/*	if (tab->opt & OPT_LR)
	reverse_lst(tab->lst);*/
	else if (tab->opt & OPT_A)
		ls_opt_a(tab);
	else if (tab->opt & OPT_L)
		ls_opt_l(tab);
	else
		simple_ls(tab);
}

int		main(int ac, char **av)
{
	int			i;
	t_struct	tab;

	i = 1;
	tab.opt = 0;
	if (!(tab.lst = (t_param **)malloc(sizeof(t_param *))))
		return (0);
	*(tab.lst) = NULL;
	while (i < ac)
		if (av[i][0] == '-')
			options(av[i++], &tab);
		else if (av[i][0] != '-')
			ft_param_push_back(tab.lst, av[i++]);
	wich_ls(&tab);
	return (0);
}
