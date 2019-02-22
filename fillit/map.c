/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:06:50 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 17:24:08 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_place_tetri(t_cont t, t_map *m)
{
	uint16_t	j;
	int			i;
	int			s;

	i = 0;
	j = 0xf;
	s = t.y;
	if (t.x + t.width > m->size || t.y + t.height > m->size)
		return (-1);
	while (i <= 12)
	{
		if ((((t.tetri & j) >> i) << t.x & m->map[t.y++]))
			return (0);
		j <<= 4;
		i += 4;
	}
	i = 0;
	j = 0xf;
	while (i <= 12)
	{
		m->map[s++] |= ((t.tetri & j) >> i) << t.x;
		j <<= 4;
		i += 4;
	}
	return (1);
}

void		ft_mapzero(void *s)
{
	uint16_t	*str;
	int			n;

	str = s;
	n = 32;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
	s = str;
}

t_map		*ft_map(void)
{
	t_map	*smap;

	if (!(smap = malloc(sizeof(t_map))) ||
		!(smap->map = malloc(sizeof(smap->map) * 16)))
		ft_error();
	return (smap);
}
