/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:05:27 by agissing          #+#    #+#             */
/*   Updated: 2018/12/11 16:00:43 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_double(double nb, int precision, int d)
{
	return (ft_put_ldouble(nb, precision, d));
}

int		ft_put_ldouble(long double nb, int precision, int d)
{
	int		count;

	count = 0;
	count += ft_putnb((long long)nb, 10, "0123456789", d);
	count += d ? ft_putchar('.') : 1;
	nb = (nb < 0) ? -nb - (long long)nb : nb - (long long)nb;
	while (precision-- > 0)
	{
		count += ft_putnb((int)(nb *= 10), 10, "0123456789", d);
		nb -= (int)nb;
	}
	return (count);
}
