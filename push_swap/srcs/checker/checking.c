/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:06:26 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 21:33:16 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_param(char c)
{
	return (c == 'c' || c == 'l' || c == 'v');
}

int		check_vals(int c, char **v, int var)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	if (var == 1)
		while (i < c)
		{
			if (!(v[i][0] == '-' && is_param(v[i][1])))
				count++;
			i++;
		}
	else
		while (i < c)
		{
			if (!(v[i][0] == '-' && is_param(v[i][1])) && !ft_isnum(v[i]))
				return (0);
			i++;
		}
	return (count <= 1);
}

int		check_args(char **str, int *val)
{
	int		i;

	i = 0;
	while (str[i])
		if (!is_int(str[i++]))
			return (0);
	*val = i;
	return (1);
}
