/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:13:37 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 19:14:22 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	total_rev(t_stack **a, t_stack **b, t_sort v)
{
	int		i;
	int		j;

	i = ft_len(*a) - 1;
	j = 0;
	swap(*a) ? ft_add_op(v.op, 1) : 0;
	(*a = rotate(*a)) ? ft_add_op(v.op, 4) : 0;
	(*a = rotate(*a)) ? ft_add_op(v.op, 4) : 0;
	while (--i)
	{
		push(a, b) ? ft_add_op(v.op, 11) : 0;
		if (j > 0)
			(*b = rotate(*b)) ? ft_add_op(v.op, 5) : 0;
		j++;
	}
	while (j--)
		push(b, a) ? ft_add_op(v.op, 10) : 0;
}

void	rev_check(t_stack **a, t_stack **b, t_sort v)
{
	if (v.count > 3 && (*a) && is_ok_b(*a, ft_len(*a)))
		return (total_rev(a, b, v));
	sort_a(a, b, v);
}
