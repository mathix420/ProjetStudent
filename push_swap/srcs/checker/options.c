/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:09:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/13 15:56:46 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_isoption(char c)
{
	return (c == 'v' || c == 'c' || c == 'l');
}

int		ft_options(char *opt, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (opt[++i])
		if (!ft_isoption(opt[i]))
		{
			ft_usage();
			return (0);
		}
		else
		{
			opt[i] == 'v' ? mlx->opt |= OPT_V : 0;
			opt[i] == 'c' ? mlx->opt |= OPT_C : 0;
			opt[i] == 'l' ? mlx->opt |= OPT_L : 0;
		}
	return (1);
}

int		ft_checkarg(char *arg, int *nb)
{
	long	out;
	int		sign;
	int		i;

	i = 0;
	out = 0;
	sign = 0;
	if (!arg || !arg[0])
		return (0);
	while ((arg[i] >= 8 && arg[i] <= 13) || arg[i] == ' ')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		sign = (arg[i++] == '-');
	if (!ft_isdigit(arg[i]))
		return (0);
	while (ft_isdigit(arg[i]))
	{
		out = (out * 10) + arg[i++] - '0';
		if (out - sign > 2147483647)
			return (0);
	}
	*nb = sign ? -out : out;
	return (!arg[i]);
}

int		get_options(int i, char **v, t_mlx *mlx)
{
	int		j;

	j = i;
	while (v[j] && v[j][0] == '-' && ft_isalpha(v[j][1]))
		ft_options(v[j++], mlx);
	if (!v[j])
		return (-1);
	i = j - 1;
	while (v[++i])
		if (v[i][0] == '-' && ft_isalpha(v[i][1]))
			ft_options(v[i], mlx);
	return (j);
}

int		options(int c, char **v, t_mlx *mlx)
{
	t_stack		*stck_a;
	int			var;
	int			i;
	int			nb;

	nb = 0;
	var = !count_param(c, v) ? 1 : 2;
	if ((i = get_options(1, v, mlx)) == -1)
		return (0);
	stck_a = NULL;
	if (var == 1 && (v = ft_strsplit(v[i], ' ')))
	{
		i = 0;
		if (!v[0] || !v[0][0])
			return (0);
		while (v[i])
			i++;
		i--;
		var = 0;
	}
	else
	{
		var = i;
		i = c - 1;
	}
	while (i >= var)
		if (!ft_checkarg(v[i--], &nb) || !(stck_a = ft_new_elem(nb, stck_a)))
			return (0);
	ft_init(mlx, stck_a, NULL);
	return (1);
}
