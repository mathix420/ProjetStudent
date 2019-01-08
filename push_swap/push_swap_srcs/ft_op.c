/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:33:27 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 19:33:30 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_op(t_op **op, int nb)
{
	t_op	*new;

	if (!*op)
	{
		if (!(*op = ft_memalloc(sizeof(t_op))))
			return ;
		(*op)->nb = nb;
		(*op)->next = NULL;
	}
	else
	{
		if (!(new = ft_memalloc(sizeof(t_op))))
			return ;
		new->nb = nb;
		new->next = *op;
		*op = new;
	}
}

void	ft_free_ops(t_op *op)
{
	t_op	*tmp;

	while (op->next)
	{
		tmp = op->next;
		free(op);
		op = tmp;
	}
	free(op);
}
