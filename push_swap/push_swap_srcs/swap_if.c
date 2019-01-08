/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:20:05 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 19:21:43 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_if_a(t_stack *pila)
{
	if (pila->nb > pila->before->nb)
	{
		swap(pila);
		return (1);
	}
	return (0);
}

int		swap_if_b(t_stack *pile)
{
	if (pile->nb < pile->before->nb)
	{
		swap(pile);
		return (1);
	}
	return (0);
}
