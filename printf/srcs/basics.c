/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:55:14 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 18:12:17 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && *str++)
		i++;
	return ((!str) ? 6 : i);
}

int		ft_putpstr(char *str, t_infos *i, int disp)
{
	int		count;
	int		d;

	if (!(M_PRES & i->data))
		return (disp ? ft_addstr(i, str) : ft_strlen(str));
	count = i->precision;
	d = 0;
	while (*str++ && count-- > 0)
		d += disp ? ft_add(i, *(str - 1)) : 1;
	return (d);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
	s = str;
}
