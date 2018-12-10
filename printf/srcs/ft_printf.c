/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/10 13:53:29 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_fill(t_infos *i, unsigned int count)
{
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

int		ft_dioux(t_infos *i, va_list vl, int count)
{
	char	*b;
	int		base;

	base = ft_get_base(i, &b); 
	if (0x1 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb((char)va_arg(vl, uint64_t), base, b);
	else if (0x2 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb((short)va_arg(vl, uint64_t), base, b);
	else if (0x8 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb(va_arg(vl, long), base, b);
	else if (0x4 << 28 & i->data && 0x300 & i->data)
		count += ft_putnb(va_arg(vl, long long), base, b);
	else if (0x1 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb((unsigned char)va_arg(vl, uint64_t), base, b);
	else if (0x2 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb((unsigned short)va_arg(vl, uint64_t), base, b);
	else if (0x8 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb(va_arg(vl, unsigned long), base, b);
	else if (0x4 << 28 & i->data && 0xf0 & i->data)
		count += ft_putunb(va_arg(vl, unsigned long long), base, b);
	else if (0x300 & i->data)
		count += ft_putnb(va_arg(vl, int), base, b);
	else if (0xf0 & i->data)
		count += ft_putunb(va_arg(vl, unsigned), base, b);
	return (ft_fill(i, count));
}

#define CONV_B (uint64_t)(0xf8 << 24)
#define L_CONV (uint64_t)(0x8 << 28)

int		ft_fcsp(t_infos *i, va_list vl)
{
	int	count;

	count = 0;
	if (i->data & 1 << 10 && (!(CONV_B & i->data) || i->data & 1 << 31))
		count += ft_put_double(va_arg(vl, double), (i->data & 4) ?
							i->precision : 6);
	else if (i->data & 1 << 10 && i->data & 1 << 27)
		count += ft_put_ldouble(va_arg(vl, long double),
								(i->data & 4) ? i->precision : 6);
	else if (i->data & 1 << 11)
	{
		count += ft_putstr("0x");
		count += ft_putunb((unsigned long)va_arg(vl, void*),
						   16, "0123456789abcdef");
	}
	else if (i->data & 1 << 12)
		count += ft_putstr(va_arg(vl, char *));
	else if (i->data & 1 << 13)
		count += ft_putchar(va_arg(vl, int));
	return (ft_fill(i, count));
}

int		ft_printf(const char *restrict format, ...)
{
	uint32_t	count;
	t_infos		*infos;
	va_list		valist;
	char		*str;

	str = (char *)format;
	va_start(valist, format);
	count = 0;
	while (*str)
		if (*str != '%')
			count += ft_putchar(*str++);
		else if (*str++ == '%' && (infos = ft_getinfos(&str)) &&
				!(infos->data & 1))
		{
			count += ft_dioux(infos, valist, 0);
			count += ft_fcsp(infos, valist);
			infos->data = 0;
			free(infos);
			str++;
		}
	va_end(valist);
	return (count);
}
