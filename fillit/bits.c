/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:14:09 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 17:29:30 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_first_square(int nb)
{
	int	i;

	i = 0;
	while (i <= nb >> 1)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (ft_first_square(nb + 1));
}

uint16_t		rev_bits(uint16_t b)
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

void			print_bis(uint16_t octet)
{
	uint16_t	oct;
	int			div;

	div = 1 << 15;
	oct = octet;
	while (div != 0)
	{
		(div & 0x888) > 0 ? write(1, "\n", 1) : 0;
		if (div <= oct && (oct = oct % div) >= 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		div >>= 1;
	}
}

uint16_t		ft_push_topleft(uint16_t tetri)
{
	while (!(tetri & 0xf000))
		tetri <<= 4;
	while (!(tetri & 0x8888))
		tetri <<= 1;
	return (tetri);
}

uint16_t		ft_tetri_to_b(char *str)
{
	uint16_t	x;
	int			i;

	i = 0;
	x = 0;
	while (*str)
	{
		if (*str == '#' || *str == '.')
			if (*str == '#' || i++ < 0)
				x |= 1 << i++;
		str++;
	}
	x = reverse_bits(ft_push_topleft(reverse_bits(x)));
	return (x);
}
