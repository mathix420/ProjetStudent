/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:05:31 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 22:32:59 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*rotate(t_stack *stack)
{
	t_stack		*first;
	t_stack		*second;

	if (!stack || !stack->before)
		return (NULL);
	first = stack;
	second = stack->before;
	while (stack->before)
		stack = stack->before;
	first->before = NULL;
	stack->before = first;
	stack = second;
	return (stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate(*stack_a);
	*stack_b = rotate(*stack_b);
}
