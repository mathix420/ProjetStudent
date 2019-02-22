/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:11:38 by agissing          #+#    #+#             */
/*   Updated: 2019/01/13 15:00:55 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_get_op(t_mlx *mlx)
{
	char	*ops;
	int		i;

	ops = NULL;
	i = 0;
	while (get_next_line(0, &ops) && ++i)
		if (!ft_add(&mlx->op, ops))
			exit(ft_error());
	if (ops)
		free(ops);
	if (mlx->opt & OPT_L)
	{
		ft_putnbr(i);
		ft_putstr(" lines\n");
	}
}

int		ft_add(t_op **op, char *ops)
{
	if (!ft_strcmp("sa", ops))
		ft_add_op(op, 1);
	else if (!ft_strcmp("sb", ops))
		ft_add_op(op, 2);
	else if (!ft_strcmp("ss", ops))
		ft_add_op(op, 3);
	else if (!ft_strcmp("ra", ops))
		ft_add_op(op, 4);
	else if (!ft_strcmp("rb", ops))
		ft_add_op(op, 5);
	else if (!ft_strcmp("rr", ops))
		ft_add_op(op, 6);
	else if (!ft_strcmp("rra", ops))
		ft_add_op(op, 7);
	else if (!ft_strcmp("rrb", ops))
		ft_add_op(op, 8);
	else if (!ft_strcmp("rrr", ops))
		ft_add_op(op, 9);
	else if (!ft_strcmp("pa", ops))
		ft_add_op(op, 10);
	else if (!ft_strcmp("pb", ops))
		ft_add_op(op, 11);
	else
		return (0);
	return (1);
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

t_op	*ft_do_op(t_mlx *mlx)
{
	t_op	*tmp;

	if (!(mlx->op))
		return (NULL);
	if (mlx->op->nb == 1 || mlx->op->nb == 2)
		swap(mlx->op->nb == 1 ? mlx->pila : mlx->pilb);
	else if (mlx->op->nb == 3)
		ss(mlx->pila, mlx->pilb);
	else if (mlx->op->nb == 4 || mlx->op->nb == 5)
		mlx->op->nb == 4 ? mlx->pila = rotate(mlx->pila) :
			(mlx->pilb = rotate(mlx->pilb));
	else if (mlx->op->nb == 6)
		rr(&mlx->pila, &mlx->pilb);
	else if (mlx->op->nb == 7 || mlx->op->nb == 8)
		mlx->op->nb == 7 ? mlx->pila = reverse(mlx->pila) :
			(mlx->pilb = reverse(mlx->pilb));
	else if (mlx->op->nb == 9)
		rrr(&mlx->pila, &mlx->pilb);
	else if (mlx->op->nb == 10 || mlx->op->nb == 11)
		mlx->op->nb == 11 ? push(&mlx->pila, &mlx->pilb) :
			push(&mlx->pilb, &mlx->pila);
	tmp = mlx->op->next;
	free(mlx->op);
	return (tmp);
}
