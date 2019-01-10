/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:04:08 by agissing          #+#    #+#             */
/*   Updated: 2019/01/10 19:04:37 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
