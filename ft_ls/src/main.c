/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/07 19:43:11 by agissing         ###   ########.fr       */
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

void	ft_free(t_param **tab)
{
	t_param	*tmp;
	t_lst	*tmp1;

	while (*tab)
	{
		tmp = *tab;
		while (*tmp->child)
		{
			tmp1 = *tmp->child;
			free((*tmp->child)->name);
			*tmp->child = (*tmp->child)->next;
			free(tmp1);
		}
		free(tmp->child);
		*tab = (*tab)->next;
		free(tmp);
	}
	free(*tab);
}

int		main(int ac, char **av)
{
	int			i;
	t_struct	tab;

	i = 1;
	tab.opt = 0;
	tab.bf.id = 0;
	ft_bzero(&tab.bf, sizeof(t_buf));
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
	tab.nb = 0;
	tab.opt & OPT_UR ? ls_rec(&tab) : ls(&tab);
	ft_free(tab.names);
	free(tab.names);
	return (0);
}
