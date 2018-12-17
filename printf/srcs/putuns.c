/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putuns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:46:33 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 20:33:54 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putuns(t_infos *i, uint64_t nbr, int d)
{
	unsigned	count;
	unsigned	n;

	i->bs = "0123456789";
	i->bn = 10;
	count = 0;
	if (M_PRES & i->data && (n = ft_putunb(nbr, i, 0)) < i->precision)
		while (n++ < i->precision)
			count += d ? ft_add(i, 48) : 1;
	return (count + ((!nbr && M_PRES & i->data && !(i->precision)) ? 0 :
					ft_putunb(nbr, i, d)));
}
