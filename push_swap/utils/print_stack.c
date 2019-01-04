/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:44:01 by agissing          #+#    #+#             */
/*   Updated: 2019/01/04 17:26:17 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

void		print_stack_numbers(t_stack *stack)
{
	if (stack->before)
	{
		print_stack_numbers(stack->before);
		ft_putchar(' ');
	}
	ft_putnbr(stack->nb);
}

void		print_stack(t_stack *stack)
{
	ft_putstr("BAS ");
	if (stack)
		print_stack_numbers(stack);
	ft_putstr(" HAUT\n");
}
