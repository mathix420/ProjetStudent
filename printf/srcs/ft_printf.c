/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/07 16:51:47 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	ft_diouxx(long long n, char *data);

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

infos_t	*ft_getinfos(char *input);

int		ft_treat(char *arg, int kwargs)
{
	ft_putstr("OK");
	arg = "";
	kwargs = 0;
	return (0);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	valist;
	int		nb_args;
	char	*str;

	nb_args = ft_countparam(format);
	str = (char *)format;
	va_start(valist, format);
	// Travail ici :: va_arg(valist, int);
	while (*str)
		(*str == '%' && str++ >= 0) ? ft_treat(str++, va_arg(valist, int)) :
			ft_putchar(*str++);
	va_end(valist);
	return (0); // TODO
}

int		main(int c, char **v)
{
	if (c > 1 && v[1])
	{
		while (*(v[1]))
		{
			if (*(v[1])++ == '%')
				printf("OUT :: %x\n", ft_getinfos(v[1])->data);
		}
	}
	return (0);
}

