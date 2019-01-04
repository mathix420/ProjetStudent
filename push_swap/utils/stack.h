/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:38:29 by agissing          #+#    #+#             */
/*   Updated: 2019/01/04 16:34:43 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*before;
}				t_stack;

void			print_stack(t_stack *stack);
void			push(t_stack **stack_a, t_stack **stack_b);
void			swap(t_stack *stack_a);
void			ss(t_stack *stack_a, t_stack *stack_b);
t_stack			*rotate(t_stack *stack);
void			rr(t_stack **stack_a, t_stack **stack_b);
t_stack			*reverse(t_stack *stack);
void			rrr(t_stack **stack_a, t_stack **stack_b);
t_stack			*ft_new_elem(int nb, t_stack *before);
t_stack			*ft_free_elem(t_stack *stack);

#endif
