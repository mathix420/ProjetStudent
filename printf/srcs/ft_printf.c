/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 15:32:32 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fill(t_infos *i, unsigned int count, int disp)
{
	while (i->data & M_MIN_SIZE && count < i->minlength)
		if ((M_LEFT & i->data) ? !disp : disp)
			count += ft_putchar(
				(M_ZERO & i->data && !((M_LEFT + M_PRES) & i->data)) ? 48 : 32);
		else
			count += 1;
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
	return (count);
}

int		ft_dioux(t_infos *i, va_list vl, int c, int d)
{
	ft_get_base(i);
	if (M_HEXS & i->data)
		c += ft_puthex(i, ft_uconv(i, va_arg(vl, uint64_t)), d);
	else if (M_OCT & i->data)
		c += ft_putoct(i, ft_uconv(i, va_arg(vl, uint64_t)), d);
	else if (M_INT & i->data)
		c += ft_putdi(i, ft_conv(i, va_arg(vl, int64_t)), d);
	else if (M_UNSI & i->data)
		c += ft_putuns(i, ft_uconv(i, va_arg(vl, int64_t)), d);
	else if (M_CHR & i->data)
		c += d ? ft_putchar(va_arg(vl, int)) : 1;
	else if (i->data & M_STR)
		c += ft_putstring(i, va_arg(vl, char *), d);
	else if (i->data & M_PTR)
		c += ft_putptr(i, va_arg(vl, void *), d);
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
			count[1] = ft_dioux(i, valist[1], 0, M_LEFT & i->data);
			ft_fill(i, count[1], !(M_LEFT & i->data));
			ft_dioux(i, valist[0], 0, !(M_LEFT & i->data));
//			printf("=1'%d'\n", count[1]);
			count[0] += ft_fill(i, count[1], M_LEFT & i->data);
			s++;
			free(i);
		}
	(i && i->data & M_ERROR) ? free(i) : 0;
	va_end(valist[1]);
	va_end(valist[0]);
	return (count[0]);
}
