/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:26:25 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 17:00:59 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthex(t_infos *i, uint64_t nbr, int d)
{
	unsigned	count;
	unsigned	nb;
	int			p;

	i->bs = (M_UHEX & i->data) ? "0123456789ABCDEFX" : "0123456789abcdefx";
	i->bn = 16;
	count = 0;
	p = (nbr == 0 && (M_PRES & i->data) && i->precision == 0);
	if (M_HASH & i->data && nbr > 0)
		count += d ? ft_putchar(48) + ft_putchar(i->bs[16]) : 2;
	if (M_PRES & i->data && (nb = ft_putunb(nbr, i, 0)) < i->precision)
		while (nb++ < i->precision)
			count += d ? ft_putchar(48) : 1;
	return (count + (!p ? ft_putunb(nbr, i, d) : 0));
}
