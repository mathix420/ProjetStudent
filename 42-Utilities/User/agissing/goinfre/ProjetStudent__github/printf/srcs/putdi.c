/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:32:11 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 19:53:37 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_putdi(t_infos *i, int64_t nbr, int d)
{
	unsigned	count;
	unsigned	n;
	int			p;

	i->bs = "0123456789";
	i->bn = 10;
	count = 0;
	p = (nbr == 0 && (M_PRES & i->data) && i->precision == 0);
	if (M_PLUS & i->data && nbr >= 0)
		count += d ? ft_add(i, '+') : 1;
	else if (nbr < 0)
		count += d ? ft_add(i, '-') : 1;
	else if (M_SPC & i->data && nbr >= 0)
		count += d ? ft_add(i, ' ') : 1;
	((M_PRES + M_ZERO) & i->data) ? n = ft_putnb(nbr, i, 0) : 0;
	if (M_PRES & i->data && n < i->precision)
		while (n++ < i->precision)
			count += d ? ft_add(i, 48) : 1;
	if (M_MIN_SIZE & i->data && M_ZERO & i->data && !(M_LEFT & i->data))
		while (count + n < i->minlength)
			count += d ? ft_add(i, 48) : 1;
	return (count + ((!p) ? ft_putnb(nbr, i, d) : 0));
}
