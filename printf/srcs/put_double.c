/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:05:27 by agissing          #+#    #+#             */
/*   Updated: 2018/12/10 19:02:04 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_double(double nb, int precision)
{
	return (ft_put_ldouble(nb, precision));
}

int		ft_put_ldouble(long double nb, int precision)
{
	int		count;

	count = 0;
	count += ft_putnb((long long)nb, 10, "0123456789");
	count += ft_putchar('.');
	nb = (nb < 0) ? -nb : nb;
	while (precision-- > 0)
	{
		nb -= (int)nb;
		count += ft_putnb((int)(nb *= 10), 10, "0123456789");
	}
	return (count);
}
