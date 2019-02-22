/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:14:09 by agissing          #+#    #+#             */
/*   Updated: 2018/11/24 22:21:30 by agissing         ###   ########.fr       */
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

unsigned short int		reverse_bits(uint16_t b)
{
	uint16_t	r;
	unsigned	byte_len;

	r = 0;
	byte_len = 16;
	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

void		print_bytes(uint16_t octet, int size)
{
	uint16_t	oct;
	int			div;

	div = 32768;
	oct = octet;
	while (div != 0)
	{
		(div & 0x888) > 0 ? write(1, "\n", 1) : 0;
		if (div <= oct && (oct = oct % div) >= 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		div = div / 2;
	}
}

uint16_t	ft_push_topleft(uint16_t tetri)
{
	while (!(tetri & 0xf000))
		tetri <<= 4;
	while (!(tetri & 0x8888))
		tetri <<= 1;
	return (tetri);
}

uint16_t	ft_tetri_to_b(char *str)
{
	uint16_t	x;
	int			i;
	int			j;

	i = 0;
	x = 0;
	while (*str)
	{
		if (*str == '#' || *str == '.')
			if (*str == '#' || i++ < 0)
				x |= 1 << i++;
		str++;
	}
	x = reverse_bits(x);
	return (x);
} 

int			main(int c, char **v)
{
	uint16_t		tetri;
	printf("\n======\tPROGRAM START\t======\n\n");

	if (c == 2)
	{
		tetri = ft_tetri_to_b(v[c - 1]);
		print_bytes(tetri, 4);
		printf("\n\n\n");
		print_bytes(ft_push_topleft(tetri), 4);
	}
	printf("\n\n======\tPROGRAM STOP\t======\n");
	return (0);
}
