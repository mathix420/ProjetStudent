/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:14:18 by agissing          #+#    #+#             */
/*   Updated: 2019/01/11 19:16:40 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_moy(t_stack *pile, int max)
{
	long long	somme;
	int			count;

	count = 1;
	somme = pile->nb;
	while (pile->before && count < max)
	{
		pile = pile->before;
		somme += pile->nb;
		count++;
	}
	return (somme / count);
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

int		ft_max(t_stack *pile, t_sort v)
{
	int		max;

	max = pile->nb;
	while (pile->before && --v.bc > 0)
	{
		pile = pile->before;
		if (pile->nb > max)
			max = pile->nb;
	}
	return (max);
}

t_stack	*ft_get_last(t_stack *pile)
{
	while (pile->before)
		pile = pile->before;
	return (pile);
}
