/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:05:31 by agissing          #+#    #+#             */
/*   Updated: 2018/12/19 19:05:47 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.c"

void	ra(t_elem *stack_a)
{
	t_elem		*last;

	last = stack_a;
	while (last->before)
		last = last->before;
	if (stack_a != last)
	{
		last->before = stack_a;
		stack_a->before = NULL;
	}
	stack_a = last;
}

void	rb(t_elem *stack_b)
{
	t_elem		*last;

	last = stack_b;
	while (last->before)
		last = last->before;
	if (stack_b != last)
	{
		last->before = stack_b;
		stack_b->before = NULL;
	}
	stack_b = last;
}

void	rr(t_elem *stack_a, t_elem *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
