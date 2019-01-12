/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:09:24 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 22:22:45 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_opt(char *str, t_mlx *mlx)
{
	int		i;

	i = 1;
	while (str[i])
	{
		str[i] == 'v' ? mlx->opt |= OPT_V : 0;
		str[i] == 'c' ? mlx->opt |= OPT_C : 0;
		str[i] == 'l' ? mlx->opt |= OPT_L : 0;
		if (!is_param(str[i]))
			ft_usage();
		i++;
	}
}

int		get_options(int i, char **v, t_mlx *mlx)
{
	int		j;

	j = i;
	while (v[j] && v[j][0] == '-' && ft_isalpha(v[j][1]))
		fill_opt(v[j++], mlx);
	if (!v[j])
		return (-1);
	i = j - 1;
	while (v[++i])
		if (v[i][0] == '-' && ft_isalpha(v[i][1]))
			fill_opt(v[i], mlx);
	return (j);
}

int		options(int c, char **v, t_mlx *mlx)
{
	t_stack		*stck_a;
	int			var;
	int			i;

	var = !count_param(c, v) ? 1 : 2;
	if ((i = get_options(1, v, mlx)) == -1)
		return (ft_error());
	if (!(stck_a = NULL) && !check_vals(c, v, var))
		return (ft_error());
	if (var == 1 && (v = ft_strsplit(v[i], ' ')))
	{
		if (!check_args(v, &i))
			return (ft_error());
	}
	else
	{
		var += (i - 1);
		i += count_param(c, v);
	}
	while (i-- >= var)
		if (!is_int(v[i]) || !(stck_a = ft_new_elem(ft_atoi(v[i]), stck_a)))
			return (ft_error());
	ft_init(mlx, stck_a, NULL);
	return (1);
}
