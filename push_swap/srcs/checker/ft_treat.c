/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:12:54 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 17:39:32 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		treat(t_mlx *mlx)
{
	int		i;

	i = 0;
	if (!mlx->op)
		return (0);
	print_both(mlx);
	mlx->op = ft_do_op(mlx);
	ft_bzero(mlx->str, mlx->siz_x * mlx->siz_y * sizeof(int));
	if (mlx->opt & OPT_V)
	{
		print_both(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		while (mlx->len < 100 && i < (mlx->len > 30 ? 10000000 : 25000000))
			i++;
	}
	return (0);
}
