/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:22:45 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 16:24:37 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int		main(int c, char **v)
{
	t_cont	*list;
	t_cont	**start;
	int		fd;
	int		nb_tetri;

	fd = 0;
	list = NULL;
	if (c != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		exit(0);
	}
	if ((fd = open(v[1], O_RDONLY)) < 0)
		ft_error();
	nb_tetri = ft_read(fd, &list);
	start = &list;
	display(*start, ft_solve(list, nb_tetri));
	return (0);
}
