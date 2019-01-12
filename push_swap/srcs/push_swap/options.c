/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:09:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 22:35:54 by agissing         ###   ########.fr       */
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

int		ft_options(int c, char **v, t_stack **stck_a, t_sort *vars)
{
	int			var;
	int			i;

	i = 0;
	var = !count_param(c, v) ? 1 : 2;
	if (var == 1 && (v = ft_strsplit(v[1], ' ')))
	{
		while (v[i])
			if (!ft_isnum(v[i++]))
				return (ft_error());
	}
	else
		i = count_param(c, v);
	vars->count = i;
	var--;
	while (i-- > 0)
		if (!is_int(v[i + var]) || !(*stck_a =
				ft_new_elem(ft_atoi(v[i + var]), *stck_a)))
			return (ft_error());
	return (1);
}
