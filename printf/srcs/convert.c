/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:24:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/08 11:04:47 by agissing         ###   ########.fr       */
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
