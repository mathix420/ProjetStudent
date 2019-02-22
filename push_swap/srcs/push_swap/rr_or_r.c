/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_or_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:23:54 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 19:24:21 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_or_ra(int re, t_stack **pila, int l, t_sort v)
{
	if (l <= 0)
		return ;
	re %= l;
	if (l - re < re)
		while (re++ < l)
		{
			*pila = rotate(*pila);
			ft_add_op(v.op, 4);
		}
	else
		while (re--)
		{
			*pila = reverse(*pila);
			ft_add_op(v.op, 7);
		}
}

void	rrb_or_rb(int re, t_stack **pilb, int l, t_sort v)
{
	if (l <= 0)
		return ;
	re %= l;
	if (l - re < re)
		while (re++ < l)
		{
			*pilb = rotate(*pilb);
			ft_add_op(v.op, 5);
		}
	else
		while (re--)
		{
			*pilb = reverse(*pilb);
			ft_add_op(v.op, 8);
		}
}
