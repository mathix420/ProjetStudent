/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:09:23 by agissing          #+#    #+#             */
/*   Updated: 2019/01/05 14:17:35 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*reverse(t_stack *stack)
{
	t_stack		*first;
	t_stack		*last;

	if (!stack || !stack->before)
		return NULL;
	first = stack;
	while (stack->before)
	{
		last = stack;
		stack = stack->before;
	}
	last->before = NULL;
	stack->before = first;
	return (stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = reverse(*stack_a);
	*stack_b = reverse(*stack_b);
}
