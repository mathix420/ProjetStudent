/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_len_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:22:30 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 19:23:24 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_a(t_stack **pila, t_sort v)
{
	int		re;

	re = 0;
	swap_if_a(*pila) ? ft_add_op(v.op, 1) : 0;
	if (!is_ok_a(*pila, ft_len(*pila)))
	{
		*pila = rotate(*pila);
		if (swap_if_a(*pila))
		{
			ft_add_op(v.op, 4);
			ft_add_op(v.op, 1);
			ft_add_op(v.op, 7);
		}
		*pila = reverse(*pila);
		swap_if_a(*pila) ? ft_add_op(v.op, 1) : 0;
	}
}

void	small_sort_b(t_stack **pila, t_stack **pilb, t_sort v)
{
	swap_if_b(*pilb) ? ft_add_op(v.op, 2) : 0;
	push(pilb, pila);
	ft_add_op(v.op, 10);
	swap_if_b(*pilb) ? ft_add_op(v.op, 2) : 0;
	push(pilb, pila);
	ft_add_op(v.op, 10);
	swap_if_a(*pila) ? ft_add_op(v.op, 1) : 0;
	push(pilb, pila);
	ft_add_op(v.op, 10);
}
