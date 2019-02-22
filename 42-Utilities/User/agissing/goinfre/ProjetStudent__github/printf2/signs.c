/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:44:17 by agissing          #+#    #+#             */
/*   Updated: 2018/12/14 12:48:32 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putsign(long long nb, t_infos *i, int d)
{
	int		count;
	int		presc;

	count = 0;
	if (M_PLUS & i->data && nb > 0 && i->bn == 10)
		count += d ? ft_putchar('+') : 1;
	if (nb < 0 && i->bn == 10)
		count += d ? ft_putchar('-') : 1;
	if (!(M_PLUS & i->data) && M_SPC & i->data && nb > 0 && i->bn == 10)
		count += d ? ft_putchar(' ') : 1;
	presc = i->precision - count;
	while (M_DIOUX & i->data && M_PRES & i->data && --presc > 0)
		count += d ? ft_putchar(48) : 1;
	return (count + ft_putnb(nb > 0 ? nb : -nb, i->bn, i->bs, d));
}

int		ft_putusign(uint64_t nb, t_infos *i, int d)
{
	int		count;
	int		presc;

	count = 0;
	if (M_PLUS & i->data && nb > 0 && i->bn == 10)
		count += d ? ft_putchar('+') : 1;
	if (!(M_PLUS & i->data) && M_SPC & i->data && nb > 0 && i->bn == 10)
		count += d ? ft_putchar(' ') : 1;
	presc = i->precision - count;
	while (M_DIOUX & i->data && M_PRES & i->data && --presc > 0)
		count += d ? ft_putchar(48) : 1;
	return (count + ft_putnb(nb, i, d));
}
