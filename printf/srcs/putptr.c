/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:12:42 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 17:53:24 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putptr(t_infos *i, void *addr, int d)
{
	return ((d ? ft_addstr(i, "0x") : 2) + ft_puthex(i, (uint64_t)addr, d));
}
