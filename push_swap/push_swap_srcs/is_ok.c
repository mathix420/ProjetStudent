/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:18:40 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 19:19:17 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ok_a(t_stack *pile, int max)
{
	while (pile->before && --max)
	{
		if (pile->nb > pile->before->nb)
			return (0);
		pile = pile->before;
	}
	return (1);
}

int		is_ok_b(t_stack *pile, int max)
{
	while (pile->before && --max)
	{
		if (pile->nb < pile->before->nb)
			return (0);
		pile = pile->before;
	}
	return (1);
}
