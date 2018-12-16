/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpercent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:16:09 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 15:36:45 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putpercent(t_infos *i, int d)
{
	unsigned	count;

	count = 0;
	if (M_LEFT & i->data)
		count += d ? ft_putchar('%') : 1;
	else
		count += 1;
	if (((M_MIN_SIZE + M_ZERO + M_LEFT) & i->data) == 0x2000008)
		while (count < i->minlength)
			count += d ? ft_putchar('0') : 1;
	else if (M_MIN_SIZE & i->data)
		while (count < i->minlength)
			count += d ? ft_putchar(' ') : 1;
	if (!(M_LEFT & i->data))
		d ? ft_putchar('%') : 0;
	return (count);
}
