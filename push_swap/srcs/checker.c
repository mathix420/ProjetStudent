/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/10 12:25:55 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_max(t_stack *pile)
{
	int		max;

	max = pile->nb;
	while (pile->before)
	{
		pile = pile->before;
		if (pile->nb > max)
			max = pile->nb;
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

void    ft_fill_pixel(t_mlx mlx, int x, int y, int color)
{
	mlx.str[x + mlx.siz_x * y] = color;
}

void	ligne(t_mlx mlx, t_off off, int ep, int len)
{
	int		i;
	int		j;

	i = mlx.siz_y - off.y - ep;
	while (i < mlx.siz_y - off.y)
	{
		j = off.x;
		while (j < off.x + len)
			ft_fill_pixel(mlx.mlx, mlx.win, j++, i, mlx.color);
		i++;
	}	
}

void	print(t_stack *pile, t_mlx mlx)
{
	t_off	off;
	int		ep;
	int		step;
	int		i;

	ep = 1000 / ft_len(pile);
	step = 500 / ft_max(pile);
	off.x = 0;
	i = 1;
	while (pile)
	{
		if (pile->nb > 0)
			mlx.color = 0x00ffff;
		else
			mlx.color = 0x99ffff;
		off.y = (i - 1) * ep;
		ligne(mlx, off, ep, ft_abs(pile->nb) * step);
		pile = pile->before;
		i++;
	}
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
	mlx.mlx = mlx_init();
	mlx.siz_x = 1000;
	mlx.siz_y = 1000;
	mlx.win = mlx_new_window(mlx.mlx, mlx.siz_x, mlx.siz_y, "Checker Push_swap");
	print(stck_a, mlx);
	mlx_loop(mlx.mlx);
}
