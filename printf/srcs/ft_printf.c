/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/12 13:28:36 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_fill(t_infos *i, unsigned int count)
{
	count += ((1 << 25) & i->data && (0x3 << 4) & i->data) ? 2 :
		((1 << 24) & i->data) != 0;
	if (i->data & 8 && count < i->minlength)
		while (count < i->minlength)
			count += ft_putchar(' ');
	return (count);
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

int		ft_dioux(t_infos *i, va_list vl, int count, int d)
{
	char	*b;
	int		base;

	base = ft_get_base(i, &b);
	if (0x1 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb((char)va_arg(vl, uint64_t), base, b, d);
	else if (0x2 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb((short)va_arg(vl, uint64_t), base, b, d);
	else if (0x8 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb(va_arg(vl, long), base, b, d);
	else if (0x4 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb(va_arg(vl, long long), base, b, d);
	else if (0x1 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb((unsigned char)va_arg(vl, uint64_t), base, b, d);
	else if (0x2 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb((unsigned short)va_arg(vl, uint64_t), base, b, d);
	else if (0x8 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb(va_arg(vl, unsigned long), base, b, d);
	else if (0x4 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb(va_arg(vl, unsigned long long), base, b, d);
	else if (0x300 & i->data)
		count += ft_putnb(va_arg(vl, int), base, b, d);
	else if (0xf0 & i->data)
		count += ft_putunb(va_arg(vl, unsigned), base, b, d);
	return (count +  ft_fcsp(i, vl, d));
}

int		ft_fcsp(t_infos *i, va_list vl, int d)
{
	int		count;

	count = 0;
	if (i->data & 1 << 10 && (!((0xf8 << 24) & i->data) || i->data & 1 << 31))
		count += ft_put_double(va_arg(vl, double), (i->data & 4) ?
							i->precision : 6, d);
	else if (i->data & 1 << 10 && i->data & 1 << 27)
		count += ft_put_ldouble(va_arg(vl, long double),
								(i->data & 4) ? i->precision : 6, d);
	else if (i->data & 1 << 11)
	{
		count += d ? ft_putstr("0x") : 2;
		count += ft_putunb((unsigned long)va_arg(vl, void*),
						16, "0123456789abcdef", d);
	}
	else if (i->data & 1 << 12)
		count += d ? ft_putstr(va_arg(vl, char *)) :
			ft_strlen(va_arg(vl, char *));
	else if (i->data & 1 << 13)
		count += d ? ft_putchar(va_arg(vl, int)) : 1;
	return (count + );
}

int		ft_more(t_infos *i, va_list vl, int d)
{
	int		count;

	count = 0;
	if ()
}

int		ft_printf(const char *restrict format, ...)
{
	uint32_t	count;
	t_infos		*i;
	va_list		valist;
	va_list		vl;
	char		*str;

	str = (char *)format;
	va_start(valist, format);
	va_copy(vl, valist);
	count = 0;
	while (*str)
		if (*str != '%')
			count += ft_putchar(*str++);
		else if (*str++ == '%' && (i = ft_getinfos(&str)) && !(i->data & 1))
		{
			count += ft_fill(i, ft_dioux(i, vl, 0, 0));
			ft_dioux(i, valist, 0, 1);
			ft_fcsp(i, valist, 1);
			!(i->data = 0) ? free(i) : 0;
			str++;
		}
	va_end(vl);
	va_end(valist);
	return (count);
}
