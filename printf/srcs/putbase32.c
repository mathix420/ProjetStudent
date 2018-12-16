/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:37:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 15:53:11 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putb32(t_infos *i, uint64_t nbr, int d)
{
	unsigned	count;
	unsigned	nb;
	int			p;

	i->bs = "ybndrfg8ejkmcpqxot1uwisza345h769";
	i->bn = 32;
	count = 0;
	p = (nbr == 0 && (M_PRES & i->data) && i->precision == 0);
	if (M_HASH & i->data && nbr > 0)
		count += d ? ft_putstr("0Z") : 2;
	((M_PRES + M_ZERO) & i->data) ? nb = ft_putunb(nbr, i, 0) : 0;
	if (M_PRES & i->data && nb < i->precision)
		while (nb++ < i->precision)
			count += d ? ft_putchar('y') : 1;
	if (M_MIN_SIZE & i->data && M_ZERO & i->data && !(M_LEFT & i->data))
		while (count < i->minlength - nb)
			count += d ? ft_putchar('y') : 1;
	return (count + (!p ? ft_putunb(nbr, i, d) : 0));
}
