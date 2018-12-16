/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:01:16 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 18:01:33 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbuff(t_infos *i)
{
	write(1, &i->buf, i->id);
	i->id = 0;
}

int		ft_add(t_infos *i, char c)
{
	(i->id == BUFSIZE_PF) ? ft_putbuff(i) : 0;
	i->buf[i->id++] = c;
	return (1);
}

int		ft_addstr(t_infos *i, char *str)
{
	int		count;

	count = 0;
	while (*str)
		count += ft_add(i, *str++);
	return (count);
}
