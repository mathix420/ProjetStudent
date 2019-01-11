/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:03:33 by agissing          #+#    #+#             */
/*   Updated: 2019/01/11 13:12:04 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_max(t_stack *pile)
{
	int		max;
	int		nb;

	max = ft_abs(pile->nb);
	while (pile->before)
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

	i = 1;
	while (pile->before)
	{
		i++;
		pile = pile->before;
	}
	return (i);
}
