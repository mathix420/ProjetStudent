/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/11 18:20:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_isnum(char *str)
{
	int		i;

	i = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == ' ' || str[i] == '-' ||
		str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i > 0 && !str[i]);
}

int		count_param(int c, char **v)
{
	int		i;
	int		nb;

	i = 1;
	nb = 0;
	while (i < c)
		if (ft_isnum(v[i++]))
			nb += 1;
	return (nb);
}

int		check_vals(int c, char **v, int var)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	if (var == 1)
		while (i < c)
		{
			if (!(v[i][0] == '-' && (v[i][1] == 'v' || v[i][1] == 'c')))
				count++;
			i++;
		}
	else
		while (i < c)
		{
			if (!(v[i][0] == '-' && (v[i][1] == 'v' || v[i][1] == 'c')) && !ft_isnum(v[i]))
				return (0);
			i++;
		}
	return (count <= 1);
}

int		check_args(char **str, int *val)
{
	int		i;

	i = 0;
	while (str[i])
		if (!ft_isnum(str[i++]))
			return (0);
	*val = i;
	return (1);
}

int		ft_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int		options(int c, char **v, t_mlx *mlx)
{
	t_stack		*stck_a;
	t_stack		*stck_b;
	int			i;
	int			var;

	stck_a = NULL;
	stck_b = NULL;
	i = 1;
	var = !count_param(c, v) ? 1 : 2;
	while (v[i][0] == '-' && (v[i][1] == 'v' || v[i][1] == 'c'))
		i++;
	if (!check_vals(c, v, var))
		return (ft_error());
	if (var == 1 && (v = ft_strsplit(v[i], ' ')))
	{
		if (!check_args(v, &i))
			return (ft_error());
	}
	else
		i = c;
	while (i-- >= var)
		if (!(stck_a = ft_new_elem(ft_atoi(v[i]), stck_a)))
			return (0);
	ft_init(mlx, stck_a, stck_b);
	return (1);
}

int		main(int c, char **v)
{
	t_mlx		mlx;

	if (c <= 1 || !options(c, v, &mlx))
		return (0);
	print_both(&mlx);
	mlx_loop_hook(mlx.mlx, &treat, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
