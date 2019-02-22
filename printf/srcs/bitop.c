/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:28:57 by agissing          #+#    #+#             */
/*   Updated: 2018/12/08 10:58:19 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_place(uint32_t *bytes, int pos)
{
	*bytes |= 1 << pos;
}

void	ft_remove(uint32_t *bytes, int pos)
{
	*bytes &= ~(1 << pos);
}

/*
** Check and place if null or put one to error bit
*/

void	ft_capin(uint32_t *bytes, int pos)
{
	if (!(*bytes & 1 << pos))
		ft_place(bytes, pos);
	else
		ft_place(bytes, 0);
}

/*
** Check and place if null or delete and put one at pos -1
*/

void	ft_capinod(uint32_t *bytes, int pos)
{
	if (!(*bytes & 1 << pos))
		ft_place(bytes, pos);
	else
	{
		ft_remove(bytes, pos);
		ft_place(bytes, pos - 1);
	}
}
