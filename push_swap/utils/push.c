/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:04:47 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 20:07:31 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		push(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a))
		return (0);
	*stack_b = ft_new_elem((*stack_a)->nb, *stack_b);
	*stack_a = ft_free_elem(*stack_a);
	return (1);
}
