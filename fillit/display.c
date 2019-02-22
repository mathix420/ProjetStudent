/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:20:35 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 17:09:07 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*empty_map(int size)
{
	char	*s;
	int		x;
	int		y;

	s = ft_strnew((size + 1) * (size));
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			s[y * (size + 1) + x] = '.';
		s[y * (size + 1) + x] = '\n';
	}
	return (s);
}

void	display(t_cont *t, int size)
{
	uint16_t	mask;
	char		*fmap;
	char		v[3];

	v[0] = 'A';
	size--;
	fmap = empty_map(size);
	while (t && (mask = 1))
	{
		v[2] = -1;
		while (++v[2] < 4)
		{
			v[1] = -1;
			while (++v[1] < 4)
			{
				if ((t->tetri & mask))
					fmap[(t->y + v[2]) * (size + 1) + v[1] + t->x] = v[0];
				mask <<= 1;
			}
		}
		v[0]++;
		t = t->next;
	}
	ft_putstr(fmap);
	ft_strdel(&fmap);
}
