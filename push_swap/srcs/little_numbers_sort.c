/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_numbers_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:29:18 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 21:49:56 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_sort(t_stack **a, t_stack **b, t_sort v, int max)
{
	while (v.bc && (max = ft_max(*b, v)) >= (*b)->nb)
	{
		if (v.bc > 1 && (*b)->before && (*b)->nb < (*b)->before->nb)
			swap(*b) ? ft_add_op(v.op, 2) : 0;
		push(b, a) ? ft_add_op(v.op, 10) : 0;
		v.bc--;
		swap_if_a(*a) ? ft_add_op(v.op, 1) : 0;
	}
}

void	little_sort(t_stack **a, t_stack **b, t_sort v)
{
	int		max;

	v.bc = 0;
	while ((*a) && (!is_ok_a(*a, ft_len(*a)) ||
					(v.bc && (*a)->nb < ft_max(*b, v))))
		if ((*a)->nb > ft_get_last(*a)->nb)
			(*a = rotate(*a)) ? ft_add_op(v.op, 4) : 0;
		else
		{
			swap_if_a(*a) ? ft_add_op(v.op, 1) : 0;
			if (!is_ok_a(*a, ft_len(*a)) || (v.bc && (*a)->nb < ft_max(*b, v)))
			{
				push(a, b) ? ft_add_op(v.op, 11) : 0;
				if ((*b)->before && (*b)->nb < (*b)->before->nb)
					swap(*b) ? ft_add_op(v.op, 2) : 0;
				v.bc++;
			}
		}
	reverse_sort(a, b, v, max);
}
