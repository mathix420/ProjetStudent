/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:37:00 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 19:23:09 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putbin(t_infos *i, uint64_t nbr, int d)
{
	unsigned	count;
	unsigned	nb;
	int			p;

	i->bs = "01";
	i->bn = 2;
	count = 0;
	p = (nbr == 0 && (M_PRES & i->data) && i->precision == 0);
	if (M_HASH & i->data && nbr > 0)
		count += d ? ft_add(i, '0') + ft_add(i, 'b') : 2;
	((M_PRES + M_ZERO) & i->data) ? nb = ft_putunb(nbr, i, 0) : 0;
	if (M_PRES & i->data && nb < i->precision)
		while (nb++ < i->precision)
			count += d ? ft_add(i, 48) : 1;
	if (M_MIN_SIZE & i->data && M_ZERO & i->data && !(M_LEFT & i->data))
		while (count + nb < i->minlength)
			count += d ? ft_add(i, 48) : 1;
	return (count + (!p ? ft_putunb(nbr, i, d) : 0));
}
