/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:05:05 by agissing          #+#    #+#             */
/*   Updated: 2019/01/10 19:05:25 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
