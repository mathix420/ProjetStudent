/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:04:47 by agissing          #+#    #+#             */
/*   Updated: 2018/12/19 19:05:11 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
