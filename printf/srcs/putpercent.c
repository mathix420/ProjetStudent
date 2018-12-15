/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpercent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:16:09 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 22:42:11 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putpercent(t_infos *i, int d)
{
	unsigned	count;

	count = 0;
	if (M_MIN_SIZE & i->data & M_ZERO & i->data)
		while (count < i->minlength)
			count += d ? ft_putchar('0') : 1;
	else
		while (count < i->minlength)
			count += d ? ft_putchar(' ') : 1;
	count += d ? ft_putchar('%') : 1;
	return (count);
}
