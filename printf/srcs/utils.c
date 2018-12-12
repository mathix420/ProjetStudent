/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:33:26 by agissing          #+#    #+#             */
/*   Updated: 2018/12/12 19:35:26 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_more(t_infos *i, unsigned count)
{
	if (M_HASH & i->data && M_HEXS & i->data)
		count += ft_putchar(48) + ft_putchar(M_UHEX & i->data ? 'X' : 'x');
	count += (M_HASH & i->data && M_OCT & i->data) ? ft_putchar(48) : 0;
}

int		ft_is_printf_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' ||
			c == ' ' || c == '%');
}

int		ft_is_printf_conv(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		ft_is_printf_arg(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f');
}
