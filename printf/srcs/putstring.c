/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:59:15 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 17:09:13 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstring(t_infos *i, char *str, int d)
{
	int		cpy;
	int		count;

	if (!str)
		return (ft_putstring(i, "(null)", d));
	if (!(M_PRES & i->data))
		return (d ? ft_putstr(str) : ft_strlen(str));
	cpy = i->precision;
	count = 0;
	while (*str++ && cpy-- > 0)
		count += d ? ft_putchar(*(str - 1)) : 1;
	return (count);
}
