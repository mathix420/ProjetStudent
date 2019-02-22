/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:39:15 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 21:28:05 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_int(char *str)
{
	long long	out;
	int			i;
	int			sign;

	i = 0;
	out = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? 1 : 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = (out * 10) + (str[i++] - '0');
		if ((out - sign) > 2147483647)
			return (0);
	}
	return (ft_isnum(str));
}
