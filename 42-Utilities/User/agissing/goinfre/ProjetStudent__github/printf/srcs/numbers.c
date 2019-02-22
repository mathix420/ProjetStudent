/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:24:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 17:57:16 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnb(long long nbr, t_infos *i, int d)
{
	uint64_t	n;
	int			count;

	count = 0;
	n = nbr < 0 ? -nbr : nbr;
	if (n >= i->bn)
	{
		count += ft_putnb(n / i->bn, i, d);
		count += ft_putnb(n % i->bn, i, d);
	}
	else
		count += d ? ft_add(i, i->bs[n % i->bn]) : 1;
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
		count += d ? ft_add(i, i->bs[nbr % i->bn]) : 1;
	return (count);
}
