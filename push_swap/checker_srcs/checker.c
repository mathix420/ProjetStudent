/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:24 by agissing          #+#    #+#             */
/*   Updated: 2018/12/19 14:08:48 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_elem *stack_a)
{
	t_elem		*tmp;

	tmp = stack_a->before->before;
	stack_a->before->before = stack_a;
	stack_a->before = tmp;
}

void	sb(t_elem *stack_b)
{
	t_elem		*tmp;

	tmp = stack_b->before->before;
	stack_b->before->before = stack_b;
	stack_b->before = tmp;
}

void	pa(t_elem *stack_a, t_elem *stack_b)
{
	t_elem		*tmp;

	tmp = stack_b->before;
	stack_b->before = stack_a;
	stack_b = tmp;
}

void	pb(t_elem *stack_a, t_elem *stack_b)
{
	t_elem		*tmp;

	tmp = stack_b->before;
	stack_a->before = stack_b;
	stack_a = tmp;
}
