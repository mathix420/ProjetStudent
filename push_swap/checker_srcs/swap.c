/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:03:38 by agissing          #+#    #+#             */
/*   Updated: 2018/12/19 19:04:07 by agissing         ###   ########.fr       */
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
