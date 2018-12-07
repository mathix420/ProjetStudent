/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:24:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/07 13:30:19 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnb(long long nbr, uint64_t base, char *b)
{
	uint64_t	i;

	(nbr < 0 && (i = -nbr)) ? ft_putchar('-') :
		(i = nbr);
	if (i >= base)
	{
		ft_putnb(i / base, base, b);
		ft_putnb(i % base, base, b);
	}
	else
		ft_putchar(b[i % base]);
}

void		ft_putd(long long nb, int base, char *b)
{
	ft_putnb((int)nb, base, b);
}

void		ft_puthh(long long nb, int base, char *b)
{
	ft_putnb((char)nb, base, b);
}

void		ft_puth(long long nb, int base, char *b)
{
	ft_putnb((short)nb, base, b);
}

void		ft_putl(long long nb, int base, char *b)
{
	ft_putnb((long)nb, base, b);
}

void		ft_putll(long long nb, int base, char *b)
{
	ft_putnb(nb, base, b);
}

void		ft_diouxx(long long n, char *data)
{
	void	(*p[5]) (long long nb, int base, char *b);
	int		i;

	i = 0;
	p[0] = ft_putd;
	p[1] = ft_puth;
	p[2] = ft_puthh;
	p[3] = ft_putl;
	p[4] = ft_putll;
	while (*data != ' ')
	{
		if (*data == 'h')
			i++;
		if (i == 3 && *data == 'l')
			i++;
		else if (*data == 'l')
			i = 3;
		data++;
	}
	(*(--data) == 'd' || *data == 'i') ? p[i](n, 10, "0123456789") : 0;
	(*data == 'o') ? p[i](n, 8, "01234567") : 0;
	(*data == 'u') ? p[i]((unsigned int)n, 10, "0123456789") : 0;
	(*data == 'x') ? p[i](n, 16, "0123456789abcdef") : 0;
	(*data == 'X') ? p[i](n, 16, "0123456789ABCDEF") : 0;
}
