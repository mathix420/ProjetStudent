/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:57:47 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/25 16:00:23 by agissing         ###   ########.fr       */
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
	return (0);
}
