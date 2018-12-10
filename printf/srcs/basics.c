/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:55:14 by agissing          #+#    #+#             */
/*   Updated: 2018/12/10 14:56:22 by agissing         ###   ########.fr       */
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
	while (*s)
		i += ft_putchar(*s++);
	return (i);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
