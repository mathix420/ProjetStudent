/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:28:47 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 17:16:42 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_place_inv(t_cont t, t_map *m)
{
	uint16_t	j;
	int			i;
	int			s;

	i = 0;
	j = 0xf;
	s = t.y;
	while (i <= 12)
	{
		m->map[s++] ^= ((t.tetri & j) >> i) << t.x;
		j <<= 4;
		i += 4;
	}
	return (1);
}

int			ft_bcktr(t_cont *tetri, t_map *m)
{
	uint32_t	i;

	i = 0;
	if (!tetri)
		return (1);
	while (i < m->max)
	{
		tetri->x = i % m->size;
		tetri->y = i / m->size;
		if (ft_place_tetri(*tetri, m) == 1)
		{
			if (ft_bcktr(tetri->next, m))
			{
				return (1);
			}
			ft_place_inv(*tetri, m);
		}
		i++;
	}
	return (0);
}

int			ft_solve(t_cont *list, int nb)
{
	t_map	*map;
	uint8_t	size;

	size = ft_first_square(nb << 2);
	map = ft_map();
	ft_mapzero(map->map);
	map->max = size * size;
	map->size = size++;
	while (!ft_bcktr(list, map) && size <= 16)
	{
		ft_mapzero(map->map);
		map->max = size * size;
		map->size = size++;
	}
	if (size > 16)
		return (0);
	return (size);
}
