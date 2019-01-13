/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:03:33 by agissing          #+#    #+#             */
/*   Updated: 2019/01/13 16:06:24 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_max(t_stack *pile)
{
	int		max;
	int		nb;

	max = ft_abs(pile->nb);
	while (pile)
	{
		nb = ft_abs(pile->nb);
		pile = pile->before;
		if (nb > max)
			max = nb;
	}
	return (max);
}

int		ft_len(t_stack *pile)
{
	int		i;

	i = 0;
	while (pile)
	{
		i++;
		pile = pile->before;
	}
	return (i);
}
