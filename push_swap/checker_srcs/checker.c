/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:24 by agissing          #+#    #+#             */
/*   Updated: 2018/12/19 18:42:26 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_elem *stack_a)
{
	t_elem		*tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->before->before;
	stack_a->before->before = stack_a;
	stack_a->before = tmp;
}

void	sb(t_elem *stack_b)
{
	t_elem		*tmp;

	if (!stack_b)
		return ;
	tmp = stack_b->before->before;
	stack_b->before->before = stack_b;
	stack_b->before = tmp;
}

void	ss(t_elem *stack_a, t_elem *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_elem *stack_a, t_elem *stack_b)
{
	t_elem		*tmp;

	if (!stack_b)
		return ;
	tmp = stack_b->before;
	stack_b->before = stack_a;
	stack_b = tmp;
}

void	pb(t_elem *stack_a, t_elem *stack_b)
{
	t_elem		*tmp;

	if (!stack_a)
		return ;
	tmp = stack_b->before;
	stack_a->before = stack_b;
	stack_a = tmp;
}

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

void	rra(t_elem *stack_a)
{
	t_elem		*last;
	t_elem		*lastlast;

	last = stack_a;
	lastlast = NULL;
	while (last->before)
	{
		lastlast = last;
		last = last->before;
	}
	if (last != stack_a && lastlast)
	{
		lastlast->before = NULL;
		last->before = stack_a;
	}
}

void	rrb(t_elem *stack_b)
{
	t_elem		*last;
	t_elem		*lastlast;

	last = stack_b;
	lastlast = NULL;
	while (last->before)
	{
		lastlast = last;
		last = last->before;
	}
	if (last != stack_b && lastlast)
	{
		lastlast->before = NULL;
		last->before = stack_b;
	}
}

void	rrr(t_elem *stack_a, t_elem *stack_b)]
{
	rra(stack_a);
	rrb(stack_b);
}
