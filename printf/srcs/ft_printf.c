/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/12 19:39:52 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_fill(t_infos *i, unsigned int count, int disp)
{
	count += (M_HASH & i->data && M_HEXS & i->data) ? 2 :
		(M_HASH & i->data && M_OCT & i->data);
	if ((M_HASH + M_ZERO + M_LEFT) & i->data && (M_ZERO + M_LEFT) & i->data && disp)
		ft_more(i, count);
	while (i->data & M_MIN_SIZE && count < i->minlength)
		if ((M_LEFT & i->data) ? !disp : disp)
			count += ft_putchar(
				(M_ZERO & i->data && !(M_LEFT & i->data)) ? '0' : ' ');
		else
			count += 1;
	if (M_HASH & i->data && !((M_ZERO + M_LEFT) & i->data) && disp)
		ft_more(i, count);
	return (count);
}

int		ft_get_base(t_infos *i, char **b)
{
	if (M_UHEX & i->data && (*b = "0123456789ABCDEF"))
		return (16);
	if (M_LHEX & i->data && (*b = "0123456789abcdef"))
		return (16);
	if (M_OCT & i->data && (*b = "01234567"))
		return (8);
	*b = "0123456789";
	return (10);
}

int		ft_fcsp(t_infos *i, va_list vl, int d)
{
	int		count;

	count = 0;
	if (i->data & M_DBL && (!((0xf8 << 24) & i->data) || i->data & 1 << 31))
		count += ft_put_double(va_arg(vl, double), (i->data & 4) ?
							   i->precision : 6, d, i);
	else if (i->data & M_DBL && i->data & MF_UL)
		count += ft_put_ldouble(va_arg(vl, long double),
								(i->data & 4) ? i->precision : 6, d, i);
	else if (i->data & M_PTR)
	{
		count += d ? ft_putstr("0x") : 2;
		count += ft_putunb((unsigned long)va_arg(vl, void*),
						16, "0123456789abcdef", d);
	}
	else if (i->data & M_STR)
		count += d ? ft_putstr(va_arg(vl, char *)) :
			ft_strlen(va_arg(vl, char *));
	else if (i->data & M_CHR)
		count += d ? ft_putchar(va_arg(vl, int)) : 1;
	return (count);
}

int		ft_dioux(t_infos *i, va_list vl, int count, int d)
{
	char	*b;
	int		base;

	base = ft_get_base(i, &b);
	if (MF_HH & i->data && M_INT & i->data)
		count += ft_putsign((char)va_arg(vl, uint64_t), base, b, d, i);
	else if (MF_H & i->data && M_INT & i->data)
		count += ft_putsign((short)va_arg(vl, uint64_t), base, b, d, i);
	else if (MF_L & i->data && M_INT & i->data)
		count += ft_putsign(va_arg(vl, long), base, b, d, i);
	else if (MF_LL & i->data && M_INT & i->data)
		count += ft_putsign(va_arg(vl, long long), base, b, d, i);
	else if (MF_HH & i->data && M_OUX & i->data)
		count += ft_putunb((uint8_t)va_arg(vl, uint64_t), base, b, d);
	else if (MF_H & i->data && M_OUX & i->data)
		count += ft_putunb((uint16_t)va_arg(vl, uint64_t), base, b, d);
	else if (MF_L & i->data && M_OUX & i->data)
		count += ft_putunb(va_arg(vl, uint32_t), base, b, d);
	else if (MF_LL & i->data && M_OUX & i->data)
		count += ft_putunb(va_arg(vl, uint64_t), base, b, d);
	else if (M_INT & i->data)
		count += ft_putsign(va_arg(vl, int), base, b, d, i);
	else if (M_OUX & i->data)
		count += ft_putunb(va_arg(vl, unsigned), base, b, d);
	return (count + ft_fcsp(i, vl, d));
}

int		ft_printf(const char *restrict format, ...)
{
	uint32_t	count, dd;
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
		else if (*str++ == '%' && (i = ft_getinfos(&str)) && !(i->data & M_ERROR))
		{
			dd = ft_dioux(i, vl, 0, 0);
//			printf("+++'%d''%d'++\n", dd, i->minlength);
			count += ft_fill(i, dd, 1); // si - alors disp == 0
			ft_dioux(i, valist, 0, 1);
//			printf("+++'%d''%d'++\n", dd, i->minlength);
			ft_fill(i, dd, (M_LEFT) & 0); // si - alors disp == 1
			!(i->data = 0) ? free(i) : 0;
			str++;
		}
	va_end(vl);
	va_end(valist);
	return (count);
}
 
