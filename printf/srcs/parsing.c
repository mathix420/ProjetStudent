/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:34:29 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 20:05:07 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getprefix(char **in, t_infos *infos)
{
	if (ft_isdigit(**in))
		infos->data |= 8;
	while (ft_isdigit(**in))
		infos->minlength = infos->minlength * 10 +
			*(*in)++ - '0';
	if (**in == '.' && *(*in)++ == '.')
	{
		infos->data |= 4;
		infos->precision = 0;
	}
	while (ft_isdigit(**in))
		infos->precision = infos->precision * 10 +
			*(*in)++ - '0';
}

void	ft_getflags(char **in, t_infos *i)
{
	while (**in && ft_is_printf_flag(**in))
	{
		(**in == '#') ? ft_place(&(i->data), 26) : 0;
		(**in == '0') ? ft_place(&(i->data), 25) : 0;
		(**in == '-') ? ft_place(&(i->data), 24) : 0;
		(**in == '+') ? ft_place(&(i->data), 23) : 0;
		(*(*in)++ == ' ') ? ft_place(&(i->data), 22) : 0;
	}
}

void	ft_getconv(char **in, t_infos *i)
{
	(ft_is_printf_conv(**in)) ? i->data &= ~MF_ALL : 0;
	(**in == 'l' && (*(*in)++ || 1)) ? ft_capinod(&(i->data), 31) : 0;
	(**in == 'l' && (*(*in)++ || 1)) ? ft_capinod(&(i->data), 31) : 0;
	(**in == 'h' && (*(*in)++ || 1)) ? ft_capinod(&(i->data), 29) : 0;
	(**in == 'h' && (*(*in)++ || 1)) ? ft_capinod(&(i->data), 29) : 0;
	(**in == 'L' && (*(*in)++ || 1)) ? ft_capin(&(i->data), 27) : 0;
}

void	ft_getoptions(char **in, t_infos *i)
{
	if (ft_is_printf_arg(**in))
	{
		(**in == 'z') ? ft_place(&(i->data), 18) : 0;
		(**in == 'U') ? ft_place(&(i->data), 17) : 0;
		(**in == 'B') ? ft_place(&(i->data), 16) : 0;
		(**in == 'b') ? ft_place(&(i->data), 15) : 0;
		(**in == '%') ? ft_place(&(i->data), 14) : 0;
		(**in == 'c') ? ft_place(&(i->data), 13) : 0;
		(**in == 's') ? ft_place(&(i->data), 12) : 0;
		(**in == 'p') ? ft_place(&(i->data), 11) : 0;
		(**in == 'f') ? ft_place(&(i->data), 10) : 0;
		(**in == 'd') ? ft_place(&(i->data), 9) : 0;
		(**in == 'i') ? ft_place(&(i->data), 8) : 0;
		(**in == 'o') ? ft_place(&(i->data), 7) : 0;
		(**in == 'u') ? ft_place(&(i->data), 6) : 0;
		(**in == 'x') ? ft_place(&(i->data), 5) : 0;
		(**in == 'X') ? ft_place(&(i->data), 4) : 0;
	}
	else
		ft_place(&(i->data), 0);
}

t_infos	*ft_getinfos(char **input, t_infos *infos)
{
	infos->data = 0;
	infos->precision = 0;
	infos->minlength = 0;
	while (ft_is_printf_flag(**input) || ft_is_printf_conv(**input) ||
		**input == '.' || ft_isdigit(**input))
	{
		ft_getflags(input, infos);
		ft_getprefix(input, infos);
		ft_getconv(input, infos);
	}
	ft_getoptions(input, infos);
	if (M_DIOUX & infos->data && M_PRES & infos->data && M_ZERO & infos->data)
		infos->data &= ~M_ZERO;
	return (infos);
}
