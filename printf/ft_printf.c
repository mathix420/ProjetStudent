/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/06 19:25:36 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

void	ft_putd(int d);
void	ft_puthh(char nb);
void	ft_puth(short nb);
void	ft_putl(long nb);
void	ft_putll(long long nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

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
	while (c-- > 1)
	{
		printf("\nNB : %d, flag : hh\n", atoi(v[c]));
		ft_puthh(atoll(v[c]));
		printf("\n%hhi\n", atoll(v[c]));
		printf("\nflag : h\n");
		ft_puth(atoll(v[c]));
		printf("\n%hi\n", atoll(v[c]));
		printf("\nno flag\n");
		ft_putd(atoll(v[c]));
		printf("\n%i\n", atoll(v[c]));
		printf("\nflag : l\n");
		ft_putl(atoll(v[c]));
		printf("\n%li\n", atoll(v[c]));
		printf("\nflag : ll\n");
		ft_putll(atoll(v[c]));
		printf("\n%lli\n", atoll(v[c]));
	}
	return (0);
}

