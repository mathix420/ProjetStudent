/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/08 15:25:08 by agissing         ###   ########.fr       */
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

void	ft_treat(t_infos *i, va_list vl)
{
	char	*b;
	int		base;

	base = ft_get_base(i, &b);
	if (0x1 << 28 & i->data && 0x300 & i->data)
		ft_putnb((char)va_arg(vl, uint64_t), 10, b);
	else if (0x2 << 28 & i->data && 0x300 & i->data)
		ft_putnb((short)va_arg(vl, uint64_t), 10, b);
	else if (0x8 << 28 & i->data && 0x300 & i->data)
		ft_putnb(va_arg(vl, long), 10, b);
	else if (0x4 << 28 & i->data && 0x300 & i->data)
		ft_putnb(va_arg(vl, long long), 10, b);
	else if (0x1 << 28 & i->data && 0xf0 & i->data)
		ft_putunb((char)va_arg(vl, uint64_t), base, b);
	else if (0x2 << 28 & i->data && 0xf0 & i->data)
		ft_putunb((short)va_arg(vl, uint64_t), base, b);
	else if (0x8 << 28 & i->data && 0xf0 & i->data)
		ft_putunb(va_arg(vl, unsigned long), base, b);
	else if (0x4 << 28 & i->data && 0xf0 & i->data)
		ft_putunb(va_arg(vl, unsigned long long), base, b);
	else if (0x300 & i->data)
		ft_putnb(va_arg(vl, int), 10, b);
	else if (0xf0 & i->data)
		ft_putunb(va_arg(vl, unsigned), base, b);
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
		if (*str++ == '%' && (infos = ft_getinfos(str)) && !(infos->data & 1))
		{
			printf("\n==%x==\n", infos->data);
			ft_treat(infos, valist);
			free(infos);
		}
	va_end(valist);
	return (count);
}

int		main(void)
{
	char		*tx;
	uint64_t	nb;

	tx = " ft_printf\n%p real printf\n";
	nb = 9525555555655555555;
	ft_printf(tx, nb);
	printf(tx, nb);
	return (0);
}
