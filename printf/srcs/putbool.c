/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:54:22 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 16:24:30 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putbool(t_infos *i, uint64_t nbr)
{
	return (i && nbr ? 0 : 0);
}
