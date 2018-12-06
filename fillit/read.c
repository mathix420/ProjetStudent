/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:27:32 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 19:07:41 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_tetri_size(char *s, char *map)
{
	int		i;

	i = -1;
	map[0] = 3;
	map[1] = 0;
	map[2] = 3;
	map[3] = 0;
	while (++i < 20)
		if (s[i] == '#')
		{
			if (i % 5 < map[0])
				map[0] = i % 5;
			if (i % 5 > map[1])
				map[1] = i % 5;
			if (i / 5 < map[2])
				map[2] = i / 5;
			if (i / 5 > map[3])
				map[3] = i / 5;
		}
}

int			ft_check_form(char *s)
{
	int		count;
	int		i;
	int		max;

	i = -1;
	max = 0;
	while (s[++i])
	{
		count = 0;
		if (s[i] == '#')
		{
			(s[i + 1] == '#') ? count++ : 0;
			(i > 0 && s[i - 1] == '#') ? count++ : 0;
			(i / 5 != 3 && s[i + 5] == '#') ? count++ : 0;
			(i / 5 != 0 && s[i - 5] == '#') ? count++ : 0;
			if (!count)
				return (0);
			count > max ? (max = count) : 1;
		}
		if ((i + 1) % 5 == 0 && s[i] != '\n')
			return (0);
	}
	return ((max >= 2) ? 1 : 0);
}

int			ft_check(char *s)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (++i < 20)
	{
		if ((i + 1) % 5)
		{
			if (s[i] != '#' && s[i] != '.')
				return (0);
			if (s[i] == '#')
				count++;
			if (count > 4)
				return (0);
		}
		else if (s[i] != '\n')
			return (0);
	}
	if (count < 4 || !ft_check_form(s))
		return (0);
	if (s[20] == '\n')
		return (2);
	return (1);
}

int			ft_read(int fd, t_cont **list)
{
	t_cont	*elem;
	char	*buf;
	char	map[5];
	int		i;
	int		r;

	i = 0;
	buf = ft_strnew(21);
	while ((r = read(fd, buf, 21) > 0))
	{
		elem = ft_create_node(list);
		if (!(map[4] = ft_check(buf)))
			ft_error();
		ft_tetri_size(buf, map);
		elem->width = (map[1] - map[0]) + 1;
		elem->height = (map[3] - map[2]) + 1;
		buf[20] = 0;
		elem->tetri = ft_tetri_to_b(buf);
		ft_bzero(buf, 22);
		i++;
	}
	free(buf);
	if (i < 1 || i > 26 || map[4] == 2)
		ft_error();
	return (i);
}
