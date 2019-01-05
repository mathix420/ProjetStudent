/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:04:57 by agissing          #+#    #+#             */
/*   Updated: 2019/01/05 18:48:39 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

typedef struct	s_rot
{
	int		re;
	int		mre;
}				t_rot;

typedef struct	s_op
{
	int			nb;
	struct s_op	next;
}				t_op;

void			sort_a(t_stack **pila, t_stack **pilb, int count, int bc);
void			sort_b(t_stack **pila, t_stack **pilb, int count);

#endif
