/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:33:26 by agissing          #+#    #+#             */
/*   Updated: 2018/12/11 17:43:20 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
