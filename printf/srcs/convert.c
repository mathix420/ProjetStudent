/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:54:15 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 14:15:07 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	ft_uconv(t_infos *i, uint64_t nbr)
{
	if (MF_HH & i->data)
		return ((uint8_t)nbr);
	else if (MF_H & i->data)
		return ((uint16_t)nbr);
	else if ((MF_L + MF_LL) & i->data)
		return ((uint64_t)nbr);
	else
		return ((unsigned)nbr);
}

int64_t		ft_conv(t_infos *i, int64_t nbr)
{
	if (MF_HH & i->data)
		return ((char)nbr);
	else if (MF_H & i->data)
		return ((short)nbr);
	else if ((MF_L + MF_LL) & i->data)
		return ((long long)nbr);
	else
		return ((int)nbr);
}
