/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:22:45 by agissing          #+#    #+#             */
/*   Updated: 2018/11/23 16:44:38 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

void	ft_read(int fd)
{
	t_cont	*list;
	int		count[2]; // count[0] = nb_tetriminos; count[1] = nb ligne vide 
	char	*buf;
	int		r;

	count[0] = 0;
	count[1] = 0;
	list = NULL;
	if (!(buf = ft_strnew(21)))
		ft_error();
	while ((r = read(fd, buf, 21)))
	{
		buf[r] = 0;
		if (r == 21 && (++count[1]) && buf[20] != '\n')
			ft_free_error(&buf);
		buf[20] = 0;
		if (!ft_check(buf) || count[0] >= 26)
			ft_free_error(&buf);
		ft_tetri_to_a(&buf, 'A' + count[0]);
		ft_create_node(&list, buf);
		count[0]++;
	}
	free(buf);
	if (count[0] == count[1])
		ft_error();
	/* ================ DEBUG ================ */
	ft_print_list(list);
	/* ================ DEBUG ================ */
	ft_solve(list, count[0]);
}

int		main(int c, char **v)
{
	int		fd;

	fd = 0;
	if (c != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		exit(0);
	}
	if ((fd = open(v[1], O_RDONLY)) < 0)
		ft_error();
	ft_read(fd);
	return (0);
}
