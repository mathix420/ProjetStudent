/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putoct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:17:56 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 17:02:31 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putoct(t_infos *i, uint64_t nbr, int d)
{
	unsigned	count;
	unsigned	nb;
	int			p;

	i->bs = "01234567";
	i->bn = 8;
	count = 0;
	p = (nbr == 0 && (M_PRES & i->data) && i->precision == 0);
	if (M_HASH & i->data && i->precision != 1)
		count += d ? ft_putchar(48) : 1;
	if (M_PRES & i->data && (nb = ft_putunb(nbr, i, 0)) < i->precision)
		while (nb++ < i->precision &&
			((M_HASH & i->data && nb < i->precision) || !(M_HASH & i->data)))
			count += d ? ft_putchar(48) : 1;
	return (count + (!p ? ft_putunb(nbr, i, d) : 0));
}
