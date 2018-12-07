/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:06:50 by agissing          #+#    #+#             */
/*   Updated: 2018/11/25 19:46:23 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_first_square(int nb)
{
	int	i;

	i = 0;
	if (nb < 1)
		return (2);
	while (i <= nb / 2)
		if (i * i == nb || i++ < 0)
			return (i);
	return (ft_first_square(nb + 1));
}

uint8_t		reverse_bits(uint8_t b)
{
	uint8_t	r;
	unsigned	byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void		print_bytes(uint8_t octet)
{
	uint8_t		oct;
	uint32_t	div;

	div = 1 << 7;
	oct = octet;
	while (div != 0)
	{
		if (div <= oct && (oct = oct % div) >= 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		div = div / 2;
	}
}

void		ft_printmap(uint8_t *map, int size)
{
	while (size--)
	{
		printf("\n");
		print_bytes(reverse_bits(*map++));
	}
}

typedef struct	s_map
{
	uint8_t	*map;
	uint8_t	nb_o;
	uint8_t	cote;
}				t_map;

void		ft_set(int id, uint8_t **map)
{
	(*map)[id / 8] |= 1 << id % 8;
}

int			ft_place_tetri(uint16_t tetri, uint8_t **map, int x, int y)// change uint16_t to t_cont
{
	uint8_t		tmp;
	uint16_t	j;
	int			i;
	int			s;

	i = 0;
	j = 0xf;
	s = x;
	while (i <= 12)
	{
		tmp = ((tetri & j) >> i) << y;
		if (tmp & (*map)[x++])
			return (0);
		j <<= 4;
		i += 4;
	}
	i = 0;
	j = 0xf;
	while (i <= 12)
	{
	 	(*map)[s++] |= ((tetri & j) >> i) << y;
		j <<= 4;
		i += 4;
	}
	return (1);
}

uint8_t		*ft_map(void)
{
	uint8_t *map;

	if (!(map = malloc(16)))
		return (NULL);
	ft_bzero(map, 16);
	return (map);
}

int			main(int c, char **v)
{
	uint8_t		*map;
	printf("\n======\tPROGRAM START\t======\n\n");

	if (c == 2)
	{
		map = ft_map();
		ft_printmap(map, 16);
        printf("\n\n\n");
		printf("A1::%d\n", ft_place_tetri((uint16_t)0x113, &map, 0, 6)); // test si sort
		printf("A2::%d\n", ft_place_tetri((uint16_t)0x113, &map, 0, 0));
		ft_printmap(map, 16);
		printf("\n\n\n");
	}
	printf("\n\n======\tPROGRAM STOP\t======\n");
	return (0);
}

/*

1100
1000
1000
0000

*/
