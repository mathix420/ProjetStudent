/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:26:33 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 22:34:11 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_free_list(t_stack *stack)
{
	t_stack		*before;

	while (stack)
	{
		before = stack->before;
		free(stack);
		stack = before;
	}
}
