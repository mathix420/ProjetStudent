/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:09:23 by agissing          #+#    #+#             */
/*   Updated: 2018/12/19 19:09:35 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.c"

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

void	rrr(t_elem *stack_a, t_elem *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
