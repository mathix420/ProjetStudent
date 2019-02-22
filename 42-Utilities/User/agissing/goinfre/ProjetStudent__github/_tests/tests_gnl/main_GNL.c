/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:11:40 by agissing          #+#    #+#             */
/*   Updated: 2018/11/19 14:12:06 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int		main(int c, char **v)
{
	char	*line;
	char	*line2;
	int     fd;
	int     fd2;
	int		out;
	int		out2;


	out = 1;
	out2 = 1;
	if (c >= 3)
	{
		if (!(fd = open(v[1], O_RDONLY)) ||
			!(fd2 = open(v[2], O_RDONLY)))
			return (0);
		line = NULL;
		if ((out = get_next_line(fd, &line)) > 0)
		{
			ft_putendl(line);
		}
		if ((out2 = get_next_line(fd2, &line2)) > 0)
		{
			ft_putendl(line2);
		}
		if ((out = get_next_line(fd, &line)) > 0)
		{
			ft_putendl(line);
		}
		if ((out2 = get_next_line(fd2, &line2)) > 0)
		{
			ft_putendl(line2);
		}
	}
	return (0);
}
