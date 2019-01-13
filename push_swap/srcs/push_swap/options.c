/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:09:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/13 11:32:40 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_param(int c, char **v)
{
	int		i;
	int		nb;

	i = 1;
	nb = 0;
	while (i < c)
		if (ft_isnum(v[i++]))
			nb += 1;
	return (nb);
}

int		ft_checkarg(char *arg, int *nb)
{
	long	out;
	int		sign;
	int		i;

	i = 0;
	out = 0;
	sign = 0;
	if (!arg || !arg[0])
		return (0);
	while ((arg[i] >= 8 && arg[i] <= 13) || arg[i] == ' ')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		sign = (arg[i++] == '-');
	if (!ft_isdigit(arg[i]))
		return (0);
	while (ft_isdigit(arg[i]))
	{
		out = (out * 10) + arg[i++] - '0';
		if (out - sign > 2147483647)
			return (0);
	}
	*nb = sign ? -out : out;
	return (!arg[i]);
}

int		ft_options(int c, char **v, t_stack **pila, t_sort *vars)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	if (!count_param(c, v) && (v = ft_strsplit(v[1], ' ')))
	{
		while (v[i])
			i++;
		vars->count = i;
		if (i > 0)
			i--;
		while (i >= 0)
			if (!ft_checkarg(v[i--], &nb) || !(*pila = ft_new_elem(nb, *pila)))
				return (0);
	}
	else
	{
		vars->count = c - 1;
		i = c - 1;
		while (i > 0)
			if (!ft_checkarg(v[i--], &nb) || !(*pila = ft_new_elem(nb, *pila)))
				return (0);
	}
	return (1);
}
