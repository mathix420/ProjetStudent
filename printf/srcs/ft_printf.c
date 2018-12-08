/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/08 12:40:56 by agissing         ###   ########.fr       */
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

void	ft_treat(t_infos *i, va_list vl)
{
	va_arg(vl, int);
	(0x4 << 27 & i->data && 0x300 & i->data) ? char : 0;
	(0x4 << 27 & i->data && 0xf0 & i->data) ? unsigned char : 0;
	(0x8 << 27 & i->data && 0x300 & i->data) ? short : 0;
	(0x8 << 27 & i->data && 0xf0 & i->data) ? unsigned short : 0;
	(0x2 << 27 & i->data && 0x300 & i->data) ? long : 0;
	(0x2 << 27 & i->data && 0xf0 & i->data) ? unsigned long : 0;
	(0x1 << 27 & i->data && 0x300 & i->data) ? long long : 0;
	(0x1 << 27 & i->data && 0xf0 & i->data) ? unsigned long long : 0;
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
	// Travail ici :: va_arg(valist, int);
	while (*str)
		if (*str++ == '%' && (infos = ft_getinfos(str)) && !(infos->data & 1))
		{
			ft_treat(infos, valist);
			free(infos);
		}
	va_end(valist);
	return (count);
}

int		main(int c, char **v)
{
	ft_printf("OUT :: %s\n", "test");
	return (0);
}
