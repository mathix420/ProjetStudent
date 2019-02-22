/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:26:25 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 19:22:33 by agissing         ###   ########.fr       */
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
		count += d ? ft_add(i, 48) + ft_add(i, i->bs[16]) : 2;
	((M_PRES + M_ZERO) & i->data) ? nb = ft_putunb(nbr, i, 0) : 0;
	if (M_PRES & i->data && nb < i->precision)
		while (nb++ < i->precision)
			count += d ? ft_add(i, 48) : 1;
	if (M_MIN_SIZE & i->data && M_ZERO & i->data && !(M_LEFT & i->data))
		while (count + nb < i->minlength)
			count += d ? ft_add(i, 48) : 1;
	return (count + (!p ? ft_putunb(nbr, i, d) : 0));
}
