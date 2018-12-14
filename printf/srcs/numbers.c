/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:24:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/14 19:13:43 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnb(long long nbr, uint64_t base, char *b, int d)
{
	uint64_t	i;
	int			count;

	count = 0;
	i = nbr < 0 ? -nbr : nbr;
	if (i >= base)
	{
		count += ft_putnb(i / base, base, b, d);
		count += ft_putnb(i % base, base, b, d);
	}
	else
		count += d ? ft_putchar(b[i % base]) : 1;
	return (count);
}

int		ft_putunb(unsigned long long nbr, t_infos *i, int d)
{
	int		count;

	count = 0;
	if (nbr >= i->bn)
	{
		count += ft_putunb(nbr / i->bn, i, d);
		count += ft_putunb(nbr % i->bn, i, d);
	}
	else
		count += d ? ft_putchar(i->bs[nbr % i->bn]) : 1;
	return (count);
}

int		ft_putsign(long long nb, int d, t_infos *i, int count)
{
	int		cc;

	if (M_PLUS & i->data && nb > 0 && i->bn == 10)
		count += d ? ft_putchar('+') : 1;
	if (nb < 0 && i->bn == 10)
		count += d ? ft_putchar('-') : 1;
	if (!(M_PLUS & i->data) && M_SPC & i->data && nb > 0 && i->bn == 10)
		count += d ? ft_putchar(' ') : 1;
	cc = i->precision - ft_putnb(nb, i->bn, i->bs, 0);
	while (M_DIOUX & i->data && M_PRES & i->data && cc-- > 0)
		count += d ? ft_putchar(48) : 1;
	return (count + ft_putnb(nb, i->bn, i->bs, d));
}


int		ft_putusign(unsigned long long nb, int d, t_infos *i, int c)
{
	int		cc;

	if (M_PLUS & i->data && nb > 0 && i->bn == 10)
		c += d ? ft_putchar('+') : 1;
	if (!(M_PLUS & i->data) && M_SPC & i->data && nb > 0 && i->bn == 10)
		c += d ? ft_putchar(' ') : 1;
	cc = i->precision - ft_putunb(nb, i, 0);
	while (M_DIOUX & i->data && M_PRES & i->data && cc-- > 0)
		c += d ? ft_putchar(48) : 1;
	return (c + ft_putunb(nb, i, d));
}
