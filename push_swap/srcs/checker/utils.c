/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:03:33 by agissing          #+#    #+#             */
/*   Updated: 2019/01/10 19:03:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_max(t_stack *pile)
{
	int		max;
	int		nb;

	max = ft_abs(pile->nb);
	while (pile->before)
	{
		nb = ft_abs(pile->nb);
		pile = pile->before;
		if (nb > max)
			max = nb;
	}
	return (max);
}

int		ft_len(t_stack *pile)
{
	int		i;

	i = 1;
	while (pile->before)
	{
		i++;
		pile = pile->before;
	}
	return (i);
}

void	ft_add_op(t_op **op, int nb)
{
	t_op	*new;
	t_op	*tmp;

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
		new->next = NULL;
		tmp = (*op);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
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
