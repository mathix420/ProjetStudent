/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:41:13 by agissing          #+#    #+#             */
/*   Updated: 2018/12/14 14:50:09 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void    ft_more(t_infos *i, unsigned count)
{
    if (M_HASH & i->data && M_HEXS & i->data)
        count += ft_putchar(48) + ft_putchar(M_UHEX & i->data ? 'X' : 'x');
    count += (M_HASH & i->data && M_OCT & i->data) ? ft_putchar(48) : 0;
}

int		ft_fill(t_infos *i, unsigned count)
{	
	if ((M_HASH + M_ZERO + M_LEFT) & i->data &&
		(M_ZERO + M_LEFT) & i->data && disp)
		ft_more(i, count);
	while (i->data & M_MIN_SIZE && count < i->minlength)
		if ((M_LEFT & i->data) ? !disp : disp)
			count += ft_putchar(
				(M_ZERO & i->data && !((M_LEFT + M_PRES) & i->data)) ? 48 : 32);
		else
			count += 1;
	if (M_HASH & i->data && !((M_ZERO + M_LEFT) & i->data) && disp)
		ft_more(i, count);
	return (count);
}

void	ft_get_base(t_infos *i)
{
	if (M_UHEX & i->data && (i->bs = "0123456789ABCDEF"))
		i->bn = 16;
	else if (M_LHEX & i->data && (i->bs = "0123456789abcdef"))
		i->bn = 16;
	else if (M_OCT & i->data && (i->bs = "01234567"))
		i->bn = 8;
	else
	{
		i->bn = 10;
		i->bs = "0123456789";
	}
}

int		ft_fcsp(t_infos *i, va_list vl, int d)
{
	int		count;

	count = 0;
	i->bs = "0123456789abcdef";
	i->bn = 16;
	if (i->data & M_DBL && (!((0xf8 << 24) & i->data) || i->data & 1 << 31))
		count += ft_put_double(va_arg(vl, double), (i->data & 4) ?
							i->precision : 6, d, i);
	else if (i->data & M_DBL && i->data & MF_UL)
		count += ft_put_ldouble(va_arg(vl, long double),
								(i->data & 4) ? i->precision : 6, d, i);
	else if (i->data & M_PTR)
		count += (d ? ft_putstr("0x") : 2) +
			ft_putunb((unsigned long)va_arg(vl, void*), i, d);
	else if (i->data & M_STR)
		count += ft_putpstr(va_arg(vl, char *), i, d);
	else if (i->data & M_CHR)
		count += d ? ft_putchar(va_arg(vl, int)) : 1;
	return (count);
}

int		ft_dioux(t_infos *i, va_list vl, int c, int d)
{
	ft_get_base(i);
	if (MF_HH & i->data && M_INT & i->data)
		c += ft_putsign((char)va_arg(vl, uint64_t), d, i);
	else if (MF_H & i->data && M_INT & i->data)
		c += ft_putsign((short)va_arg(vl, uint64_t), d, i);
	else if (MF_L & i->data && M_INT & i->data)
		c += ft_putsign(va_arg(vl, long), d, i);
	else if (MF_LL & i->data && M_INT & i->data)
		c += ft_putsign(va_arg(vl, long long), d, i);
	else if (MF_HH & i->data && M_OUX & i->data)
		c += ft_putusign((uint8_t)va_arg(vl, uint64_t), d, i, c);
	else if (MF_H & i->data && M_OUX & i->data)
		c += ft_putusign((uint16_t)va_arg(vl, uint64_t), d, i, c);
	else if (MF_L & i->data && M_OUX & i->data)
		c += ft_putusign(va_arg(vl, unsigned long), d, i, c);
	else if (MF_LL & i->data && M_OUX & i->data)
		c += ft_putusign(va_arg(vl, unsigned long long), d, i, c);
	else if (M_INT & i->data)
		c += ft_putsign(va_arg(vl, int), d, i);
	else if (M_OUX & i->data)
		c += ft_putusign(va_arg(vl, unsigned), d, i, c);
	return (c + ft_fcsp(i, vl, d));
}

int		ft_printf(const char *restrict format, ...)
{
	uint32_t	count[2];
	va_list		valist[2];
	t_infos		*i;
	char		*s;

	s = (char *)format;
	i = NULL;
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
	(i && i->data & M_ERROR) ? free(i) : 0;
	va_end(valist[1]);
	va_end(valist[0]);
	return (count[0]);
}
