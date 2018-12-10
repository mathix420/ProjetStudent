/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:24:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/10 12:15:01 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnb(long long nbr, uint64_t base, char *b)
{
	uint64_t	i;
	int			count;

	count = 0;
	if (nbr < 0 && (i = -nbr))
		count += ft_putchar('-');
	else
		i = nbr;
	if (i >= base)
	{
		count += ft_putnb(i / base, base, b);
		count += ft_putnb(i % base, base, b);
	}
	else
		count += ft_putchar(b[i % base]);
	return (count);
}

int		ft_putunb(unsigned long long nbr, uint64_t base, char *b)
{
	int		count;

	count = 0;
	if (nbr >= base)
	{
		count += ft_putunb(nbr / base, base, b);
		count += ft_putunb(nbr % base, base, b);
	}
	else
		count += ft_putchar(b[nbr % base]);
	return (count);
}
