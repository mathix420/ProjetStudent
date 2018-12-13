/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/13 14:41:51 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_fill(t_infos *i, unsigned int count, int disp)
{
	int		cc;

	cc = i->precision;
	count += (M_HASH & i->data && M_HEXS & i->data) ? 2 :
		(M_HASH & i->data && M_OCT & i->data);
	if ((M_HASH + M_ZERO + M_LEFT) & i->data &&
		(M_ZERO + M_LEFT) & i->data && disp)
		ft_more(i, count);
	cc -= count;
	count = (M_PRES & i->data && M_DIOUX & i->data) ? i->precision : count;
	while (i->data & M_MIN_SIZE && count < i->minlength)
		if ((M_LEFT & i->data) ? !disp : disp)
			count += ft_putchar(
				(M_ZERO & i->data && !((M_LEFT + M_PRES) & i->data)) ? 48 : 32);
		else
			count += 1;
	while (M_DIOUX & i->data && M_PRES & i->data && cc-- > 0)
		count += disp ? ft_putchar(48) : 1;
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
		count += (d ? ft_putstr("0x") : 2) +
			ft_putunb((unsigned long)va_arg(vl, void*),
				16, "0123456789abcdef", d);
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
	uint32_t	count[2];
	va_list		valist[2];
	t_infos		*i;
	char		*s;

	s = (char *)format;
	va_start(valist[0], format);
	va_copy(valist[1], valist[0]);
	count[0] = 0;
	while (*s)
		if (*s != '%')
			count[0] += ft_putchar(*s++);
		else if (*s++ == '%' && (i = ft_getinfos(&s)) && !(i->data & M_ERROR))
		{
			count[1] = ft_dioux(i, valist[1], 0, 0);
			count[0] += ft_fill(i, count[1], 1);
			ft_dioux(i, valist[0], 0, 1);
			ft_fill(i, count[1], 0);
			!(i->data = 0) ? free(i) : 0;
			s++;
		}
	(i->data & M_ERROR) ? free(i) : 0;
	va_end(valist[1]);
	va_end(valist[0]);
	return (count[0]);
}
