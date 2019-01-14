/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:30:28 by agissing          #+#    #+#             */
/*   Updated: 2019/01/14 13:36:27 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack **pila, t_stack **pilb, t_sort v)
{
	int		i[4];

	i[3] = v.bc;
	if (!(i[1] = 0) && i[3] == 3)
		return (small_sort_b(pila, pilb, v));
	else if (i[3] == 2 && !is_ok_b(*pilb, 2))
		swap(*pilb) ? ft_add_op(v.op, 2) : 0;
	if (i[3] <= 1 || (!(i[2] = 0) && i[3] <= 1) || is_ok_b(*pilb, i[3]))
	{
		while (i[3]-- > 0)
			push(pilb, pila) ? ft_add_op(v.op, 10) : 0;
		return ;
	}
	i[0] = ft_moy(*pilb, i[3]);
	while (i[3]-- > 0)
		if ((*pilb)->nb < i[0] && ++i[1])
			(*pilb = rotate(*pilb)) ? ft_add_op(v.op, 5) : 0;
		else if (++i[2] > 0)
			push(pilb, pila) ? ft_add_op(v.op, 10) : 0;
	rrb_or_rb(i[1], pilb, ft_len(*pilb), v);
	v.bc -= i[2];
	v.count = i[2];
	sort_a(pila, pilb, v);
	sort_b(pila, pilb, v);
}

void	sort_a(t_stack **pila, t_stack **pilb, t_sort v)
{
	int		i[4];

	if (((i[3] = v.count) < 8 && i[3] == ft_len(*pila)) || (i[3] <= 1))
		return (little_sort(pila, pilb, v));
	if (!(i[2] = 0) && i[3] == 3)
		return (small_sort_a(pila, v));
	else if (!(i[1] = 0) && i[3] == 2 && !is_ok_a(*pila, i[3]))
	{
		if (v.bc == 2 && !is_ok_b(*pilb, 2))
			ss(*pila, *pilb) ? ft_add_op(v.op, 3) : 0;
		else
			swap(*pila) ? ft_add_op(v.op, 1) : 0;
		return ;
	}
	i[0] = ft_moy(*pila, i[3]);
	while (i[3]-- > 0)
		if ((*pila)->nb >= i[0] && ++i[1])
			(*pila = rotate(*pila)) ? ft_add_op(v.op, 4) : 0;
		else if (++i[2])
			push(pila, pilb) ? ft_add_op(v.op, 11) : 0;
	rra_or_ra(i[1], pila, ft_len(*pila), v);
	v.count -= i[2];
	v.bc = i[2];
	sort_a(pila, pilb, v);
	sort_b(pila, pilb, v);
}
