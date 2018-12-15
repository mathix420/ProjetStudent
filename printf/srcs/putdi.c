/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putdi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:32:11 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 14:42:26 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putdi(t_infos *i, int64_t nbr, int d)
{
	unsigned	count;
	unsigned	n;

	i->bs = "0123456789";
	i->bn = 10;
	count = 0;
	if (M_PLUS & i->data && nbr > 0)
		count += d ? ft_putchar('+') : 1;
	else if (nbr < 0)
		count += d ? ft_putchar('-') : 1;
	else if (M_SPC & i->data && nbr > 0)
		count += d ? ft_putchar(' ') : 1;
	if (M_PRES & i->data && (n = ft_putnb(nbr, i->bn, i->bs, 0)) < i->precision)
		while (n++ < i->precision)
			count += d ? ft_putchar(48) : 1;
	return (count + ft_putnb(nbr, i->bn, i->bs, d));
}
