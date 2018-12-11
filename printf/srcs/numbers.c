/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:24:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/11 16:02:02 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnb(long long nbr, uint64_t base, char *b, int d)
{
	uint64_t	i;
	int			count;

	count = 0;
	if (nbr < 0 && (i = -nbr))
		count += d ? ft_putchar('-') : 1;
	else
		i = nbr;
	if (i >= base)
	{
		count += ft_putnb(i / base, base, b, d);
		count += ft_putnb(i % base, base, b, d);
	}
	else
		count += d ? ft_putchar(b[i % base]) : 1;
	return (count);
}

int		ft_putunb(unsigned long long nbr, uint64_t base, char *b, int d)
{
	int		count;

	count = 0;
	if (nbr >= base)
	{
		count += ft_putunb(nbr / base, base, b, d);
		count += ft_putunb(nbr % base, base, b, d);
	}
	else
		count += d ? ft_putchar(b[nbr % base]) : 1;
	return (count);
}
