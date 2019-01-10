/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/10 18:57:44 by agissing         ###   ########.fr       */
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

void    ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
{
	mlx->str[x + mlx->siz_x * y] = color;
}

void	ligne(t_mlx *mlx, t_off off, int ep, int len)
{
	int		i;
	int		j;

	i = mlx->siz_y - off.y - ep;
	while (i < mlx->siz_y - off.y)
	{
		j = off.x;
		while (j < off.x + len)
			ft_fill_pixel(mlx, j++, i, mlx->color);
		i++;
	}	
}

void	print(t_mlx *mlx, t_off off, t_stack *pile)
{
	int		i;

	i = 1;
	while (pile)
	{
		if (pile->nb > 0)
			mlx->color = 0xf7ca18;
		else
			mlx->color = 0x5333ed;
		off.y = (i - 1) * mlx->ep;
		ligne(mlx, off, mlx->ep, ft_abs(pile->nb) * mlx->step);
		pile = pile->before;
		i++;
	}
}

void	print_both(t_mlx *mlx)
{
	t_off	off;

	off.x = 0;
	print(mlx, off, mlx->pila);
	off.x = 505;
	print(mlx, off, mlx->pilb);
}

t_op	*ft_do_op(t_mlx *mlx)
{
	t_op	*tmp;

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

int		treat(t_mlx *mlx)
{
	int		i;

	i = 0;
	if (!mlx->op)
		return (0);
	print_both(mlx);
	mlx->op = ft_do_op(mlx);
	ft_bzero(mlx->str, mlx->siz_x * mlx->siz_y * sizeof(int));
	print_both(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
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

void	ft_get_op(t_op **op)
{
	char	*ops;

	ops = NULL;
	while (get_next_line(0, &ops))
		if (!ft_add(op, ops))
			ft_putstr("Error TODO !!!!!!");
	if (ops)
		free(ops);
}

void	ft_init(t_mlx *mlx, t_stack *stck_a, t_stack *stck_b)
{
    int     bpp;
    int     s_l;
    int     endian;

	mlx->mlx = mlx_init();
	mlx->len = ft_len(stck_a);
	mlx->ep = 1000 / mlx->len;
	mlx->siz_x = 1005;
	mlx->siz_y = mlx->ep * mlx->len;
	mlx->step = 500 / ft_max(stck_a);
	mlx->win = mlx_new_window(mlx->mlx, mlx->siz_x, mlx->siz_y, "Checker Push_swap");
	mlx->pila = stck_a;
	mlx->pilb = stck_b;
	ft_get_op(&mlx->op);
	mlx->img = mlx_new_image(mlx->mlx, mlx->siz_x, mlx->siz_y);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
}

int		main(int c, char **v)
{
	t_stack		*stck_a;
	t_stack		*stck_b;
	t_mlx		mlx;
	int			i;

	if (c <= 2)
		return (0);
	i = c - 1;
	stck_a = NULL;
	if (!(stck_b = NULL) && c < 3)
		return (0);
	while (i >= 1)
		if (!(stck_a = ft_new_elem(ft_atoi(v[i--]), stck_a)))
			return (0);
	ft_init(&mlx, stck_a, stck_b);
	print_both(&mlx);

	mlx_loop_hook(mlx.mlx, &treat, &mlx);
	mlx_loop(mlx.mlx);
}
