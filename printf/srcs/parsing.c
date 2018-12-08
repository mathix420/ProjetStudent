/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:34:29 by agissing          #+#    #+#             */
/*   Updated: 2018/12/08 11:26:45 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getprefix(char **in, t_infos *infos)
{
	infos->data &= ~12;
	if (ft_isdigit(**in))
		infos->data |= 8;
	else if (**in == '.' && *(*in)++)
		infos->data |= 4;
	infos->precision = 0;
	infos->minlength = 0;
	while (((!infos->precision && !infos->minlength) || *(*in)++) &&
		infos->data & 12 && ft_isdigit(**in))
		if (infos->data & 4)
			infos->precision = infos->precision * 10 + **in - '0';
		else
			infos->minlength = infos->minlength * 10 + **in - '0';
}

void	ft_getflags(char **in, t_infos *i)
{
	while (**in && ft_is_printf_flag(**in))
	{
		(**in == '#') ? ft_capin(&(i->data), 26) : 0;
		(**in == '0') ? ft_capin(&(i->data), 25) : 0;
		(**in == '-') ? ft_capin(&(i->data), 24) : 0;
		(**in == '+') ? ft_capin(&(i->data), 23) : 0;
		(*(*in)++ == ' ') ? ft_capin(&(i->data), 22) : 0;
	}
}

void	ft_getconv(char **in, t_infos *i)
{
	while (**in && ft_is_printf_conv(**in))
	{
		(**in == 'l') ? ft_capinod(&(i->data), 31) : 0;
		(**in == 'h') ? ft_capinod(&(i->data), 29) : 0;
		(*(*in)++ == 'L') ? ft_capin(&(i->data), 27) : 0;
	}
}

void	ft_getoptions(char **in, t_infos *i)
{
	if (ft_is_printf_arg(**in))
	{
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

t_infos	*ft_getinfos(char *input)
{
	t_infos		*infos;

	if (!(infos = malloc(sizeof(t_infos))))
		return (NULL);
	ft_getflags(&input, infos);
	ft_getprefix(&input, infos);
	ft_getconv(&input, infos);
	ft_getoptions(&input, infos);
	return (infos);
}
