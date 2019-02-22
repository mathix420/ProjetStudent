/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:03:38 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 22:21:21 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		swap(t_stack *stack)
{
	int		tmp;

	if (!stack || !stack->before)
		return (0);
	tmp = stack->nb;
	stack->nb = stack->before->nb;
	stack->before->nb = tmp;
	return (1);
}

int		ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return (1);
}
