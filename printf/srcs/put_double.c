/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:05:27 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 16:14:18 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_ldouble(long double nb, int precision, int d, t_infos *i)
{
	int		count;
	int		sv;

	count = 0;
	i->bn = 10;
	i->bs = "0123456789";
	sv = i->precision;
	i->precision = 0;
	count += ft_putdi(i, (long long)nb, d);
	i->precision = sv;
	if (i->precision > 0)
		count += d ? ft_putchar('.') : 1;
	nb = (nb < 0) ? -nb : nb;
	nb -= (long long)nb;
	while (precision-- > 0)
	{
		count += ft_putnb((int)(nb *= 10), 10, "0123456789", d);
		nb -= (int)nb;
	}
	return (count);
}
