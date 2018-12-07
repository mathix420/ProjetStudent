/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/07 13:29:59 by agissing         ###   ########.fr       */
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

#include "stdlib.h"

int		main(int c, char **v)
{
	ft_printf("Test %iL%s %d %d %s %dede");
	ft_printf("\n\nnb param %d\n", ft_countparam("Test %iL%s %d %d %s %dede"));
	printf("\n\nnb param %d\n", ft_countparam("Test %iL%s %d %d %s %dede"));
/*	ft_putnbr_base(atoi(v[1]), atoi(v[2]), "0123456789abcdef");*/
	while (c-- > 2)
	{
		printf("\nNB : %d, flag : %s\n", atoi(v[c]), v[1]);
		ft_diouxx(atoll(v[c]), v[1]);
		ft_putchar('\n');
		printf(v[1], atoll(v[c]));
		printf("\n");
	}
	return (0);
}

