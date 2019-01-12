/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 22:38:08 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_ok_a(t_stack *pile, int max)
{
	while (pile->before && --max)
	{
		if (pile->nb > pile->before->nb)
			return (0);
		pile = pile->before;
	}
	return (1);
}

int		main(int c, char **v)
{
	t_mlx		mlx;

	if (c <= 1 || !options(c, v, &mlx))
		return (0);
	if (mlx.opt & OPT_V)
	{
		print_both(&mlx);
		mlx_loop_hook(mlx.mlx, &treat, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		while (mlx.op)
			mlx.op = ft_do_op(&mlx);
	ft_putstr(mlx.pila && is_ok_a(mlx.pila, mlx.len) ? "OK\n" : "KO\n");
	return (0);
}
