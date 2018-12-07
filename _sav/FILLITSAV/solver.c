/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:28:47 by agissing          #+#    #+#             */
/*   Updated: 2018/11/24 18:04:37 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char	reverse_bits(char b)
{
	char		r;
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

void	print_bits(char octet)
{
	int	oct;
	int	div;

	div = 128;
	oct = octet;
	while (div != 0)
	{
		if (div <= oct)
		{
			write(1, "1", 1);
			oct = oct % div;
		}
		else
		{
			write(1, "0", 1);
		}
		div = div / 2;
	}
}

void	print_bytes(char *bytes)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		print_bits(bytes[i]);
		i++;
	}
}

char		*ft_tetri_to_b(t_cont *list)
{
	char	*x;
	int		i;
	int		j;

	i = 0;
	x = ft_strnew(1);
	while (*(list->tetri))
	{
		if (i >= 8)
		{
			x[j] = reverse_bits(x[j]);
			j++;
			i = 0;
		}
		if (*(list->tetri) == '#' || *(list->tetri) == '.')
			if (*(list->tetri) == '#' || i++ < 0)
				x[j] |= 1 << i++;
		list->tetri++;
	}
	return (x);
	print_bytes(x);
}


void		ft_solve(t_cont *list, int nb_tetri)
{
	char	*grid;
	int		c;

	list = NULL;
	c = ft_first_square(nb_tetri * 4);
	if (!(grid = ft_strnew(c * c)))
		ft_error();
	printf("%d\n", c);
	// ft_print_list(list);
	// print solution
	free(grid);
}
