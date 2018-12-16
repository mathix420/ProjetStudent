/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:33:26 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 15:45:39 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_more(t_infos *i, unsigned count, int d)
{
	char	c;

	c = M_UHEX & i->data ? 'X' : 'x';
	if (M_HASH & i->data && M_HEXS & i->data)
		count += d ? ft_putchar(48) + ft_putchar(c) : 2;
	if (M_HASH & i->data && M_OCT & i->data)
		d ? ft_putchar(48) : 1;
	return (count);
}

int		ft_is_printf_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' ||
			c == ' ');
}

int		ft_is_printf_conv(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		ft_is_printf_arg(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' ||
			c == '%' || c == 'b' || c == 'B' || c == 'U' || c == 'z');
}

void	ft_free(t_infos **i)
{
	(*i)->bs = NULL;
	(*i)->data = 0;
	(*i)->precision = 0;
	(*i)->minlength = 0;
	(*i)->bn = 0;
	free(*i);
}
