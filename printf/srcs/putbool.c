/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:54:22 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 19:03:36 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putbool(t_infos *i, uint64_t nbr, int d)
{
	int		count;

	count = 0;
	if (nbr)
		count += d ? ft_addstr(i, "True") : 1;
	else
		count += d ? ft_addstr(i, "False") : 1;
	return (count);
}
