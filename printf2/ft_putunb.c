/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:41:09 by agissing          #+#    #+#             */
/*   Updated: 2018/12/14 12:43:09 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putunb(uint64_t nbr, int base, char *b, int d)
{
	int			count;

	count = 0;
	if (nbr >= (uint64_t)base)
	{
		count += ft_putnb(nbr / (uint64_t)base, base, b, d);
		count += ft_putnb(nbr % (uint64_t)base, base, b, d);
	}
	else
		count += d ? ft_putchar(b[nbr % (uint64_t)base]) : 1;
	return (count);
}
