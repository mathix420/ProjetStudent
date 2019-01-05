/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:04:57 by agissing          #+#    #+#             */
/*   Updated: 2019/01/05 20:06:10 by agissing         ###   ########.fr       */
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
	struct s_op	*next;
}				t_op;

typedef struct	s_sort
{
	int		count;
	int		bc;
	t_op	**op;
}				t_sort;

void			sort_a(t_stack **pila, t_stack **pilb, t_sort v);
void			sort_b(t_stack **pila, t_stack **pilb, t_sort v);

#endif
