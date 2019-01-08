/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:44:10 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 18:29:03 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_new_elem(int nb, t_stack *before)
{
	t_stack		*st;

	if (!(st = ft_memalloc(sizeof(t_stack))))
		return (NULL);
	st->before = before;
	st->nb = nb;
	return (st);
}

t_stack	*ft_free_elem(t_stack *stack)
{
	t_stack *before;

	before = stack->before;
	free(stack);
	return (before);
}
