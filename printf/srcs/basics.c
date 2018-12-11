/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:55:14 by agissing          #+#    #+#             */
/*   Updated: 2018/12/11 18:08:40 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char const *s)
{
	int		i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
		i += ft_putchar(*s++);
	return (i);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && *str++)
		i++;
	return ((!str) ? 6 : i);
}
