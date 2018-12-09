/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:05:27 by agissing          #+#    #+#             */
/*   Updated: 2018/12/09 17:24:31 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_double(double nb, int precision)
{
	ft_put_ldouble(nb, precision);
}

void	ft_put_ldouble(long double nb, int precision)
{
	ft_putnb((int)nb, 10, "0123456789");
	ft_putchar('.');
	nb = (nb < 0) ? -nb : nb;
	while (precision-- > 0)
	{
		nb -= (int)nb;
		ft_putnb((int)(nb *= 10), 10, "0123456789");
	}
}
