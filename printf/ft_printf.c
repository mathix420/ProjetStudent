/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:31:49 by agissing          #+#    #+#             */
/*   Updated: 2018/12/06 17:41:46 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

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

int		ft_treat(char arg, int kwargs)
{
	int		i;
	char	fcts[] = {'c', 's', 'p', 'b', 'f', '%', 'd', 'i', 'o', 'u', 'x', 'X'};

	i = -1;
	kwargs = 1;
	while (++i < 12)
		if (fcts[i] == arg)
			ft_putstr("OK");
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
		(*str == '%' && str++ >= 0) ? ft_treat(*str++, va_arg(valist, int)) :
			ft_putchar(*str++);
	va_end(valist);
	return (0); // TODO
}

int		main(void)
{
	ft_printf("Test %iL%s %d %d %s %dede");
	ft_printf("\n\nnb param %d\n", ft_countparam("Test %iL%s %d %d %s %dede"));
	printf("\n\nnb param %d\n", ft_countparam("Test %iL%s %d %d %s %dede"));
	return (0);
}

