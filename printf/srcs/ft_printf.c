/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/09 18:47:25 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_countparam(const char *str)
{
	int		nb;

	nb = 0;
	while (*str)
		if (*str++ == '%')
			if (nb++ >= 0 && *str == '%')
				str++;
	return (nb);
}

int		ft_get_base(t_infos *i, char **b)
{
	if (0x10 & i->data && (*b = "0123456789ABCDEF"))
		return (16);
	if (0x20 & i->data && (*b = "0123456789abcdef"))
		return (16);
	if (0x80 & i->data && (*b = "01234567"))
		return (8);
	*b = "0123456789";
	return (10);
}

void	ft_dioux(t_infos *i, va_list vl)
{
	char	*b;
	int		base;

	base = ft_get_base(i, &b); 
	if (0x1 << 28 & i->data && 0x300 & i->data)
		ft_putnb((char)va_arg(vl, uint64_t), base, b);
	else if (0x2 << 28 & i->data && 0x300 & i->data)
		ft_putnb((short)va_arg(vl, uint64_t), base, b);
	else if (0x8 << 28 & i->data && 0x300 & i->data)
		ft_putnb(va_arg(vl, long), base, b);
	else if (0x4 << 28 & i->data && 0x300 & i->data)
		ft_putnb(va_arg(vl, long long), base, b);
	else if (0x1 << 28 & i->data && 0xf0 & i->data)
		ft_putunb((unsigned char)va_arg(vl, uint64_t), base, b);
	else if (0x2 << 28 & i->data && 0xf0 & i->data)
		ft_putunb((unsigned short)va_arg(vl, uint64_t), base, b);
	else if (0x8 << 28 & i->data && 0xf0 & i->data)
		ft_putunb(va_arg(vl, unsigned long), base, b);
	else if (0x4 << 28 & i->data && 0xf0 & i->data)
		ft_putunb(va_arg(vl, unsigned long long), base, b);
	else if (0x300 & i->data)
		ft_putnb(va_arg(vl, int), base, b);
	else if (0xf0 & i->data)
		ft_putunb(va_arg(vl, unsigned), base, b);
}

#define CONV_B (uint64_t)(0xf8 << 24)
#define L_CONV (uint64_t)(0x8 << 28)

void	ft_fcsp(t_infos *i, va_list vl)
{
	if (i->data & 1 << 10 && (!(CONV_B & i->data) || i->data & 1 << 31))
		ft_put_double(va_arg(vl, double), (i->data & 4) ? i->precision : 6);
	else if (i->data & 1 << 10 && i->data & 1 << 27)
		ft_put_ldouble(va_arg(vl, long double), (i->data & 4) ? i->precision : 6);
	else if (i->data & 1 << 11)
	{
		ft_putstr("0x");
		ft_putunb((unsigned long)va_arg(vl, void*), 16, "0123456789abcdef");
	}
	else if (i->data & 1 << 12)
		ft_putstr(va_arg(vl, char *));
	else if (i->data & 1 << 13)
		ft_putchar(va_arg(vl, int));
}

int		ft_printf(const char *restrict format, ...)
{
	uint32_t	count;
	t_infos		*infos;
	va_list		valist;
	int			nb_args;
	char		*str;

	nb_args = ft_countparam(format);
	str = (char *)format;
	va_start(valist, format);
	count = 0;
	while (*str)
		if (*str != '%')
			ft_putchar(*str++);
		else if (*str++ == '%' && (infos = ft_getinfos(&str)) &&
				!(infos->data & 1))
		{
			ft_dioux(infos, valist);
			ft_fcsp(infos, valist);
			infos->data = 0;
			free(infos);
			str++;
		}
	va_end(valist);
	return (count);
}
