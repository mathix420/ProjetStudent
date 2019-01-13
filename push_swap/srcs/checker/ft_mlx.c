/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:04:08 by agissing          #+#    #+#             */
/*   Updated: 2019/01/13 16:17:35 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_init(t_mlx *mlx, t_stack *stck_a, t_stack *stck_b)
{
	int		bpp;
	int		s_l;
	int		endian;

	mlx->len = ft_len(stck_a);
	mlx->ep = 1000 / mlx->len;
	mlx->siz_x = 1005;
	mlx->siz_y = mlx->ep * mlx->len;
	if ((bpp = ft_max(stck_a)))
		mlx->step = 500 / bpp;
	else
		mlx->step = 0;
	mlx->pila = stck_a;
	mlx->pilb = stck_b;
	ft_get_op(mlx);
	if (mlx->opt & OPT_V)
	{
		if (!mlx->step)
		{
			ft_putstr("Cannot display these values !\n");
			exit(0);
		}
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, mlx->siz_x, mlx->siz_y,
								"Checker Push_swap");
		mlx->img = mlx_new_image(mlx->mlx, mlx->siz_x, mlx->siz_y);
		mlx->str = (int *)mlx_get_data_addr(mlx->img, &bpp, &s_l, &endian);
	}
}

void	ft_fill_pixel(t_mlx *mlx, int x, int y, int color)
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
