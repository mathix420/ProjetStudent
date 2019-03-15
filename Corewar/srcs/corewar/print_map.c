/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:59:56 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/15 11:36:55 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_color(int color)
{
	if (color == 0)
		ft_putstr("\033[0m");
	else if (color == 1)
		ft_putstr("\033[32m");
	else if (color == 2)
		ft_putstr("\033[34m");
	else if (color == 3)
		ft_putstr("\033[31m");
	else if (color == 4)
		ft_putstr("\033[35m");
}

void	print_map(t_map *map)
{
	int		i;

	i = 0;
	ft_putendl("");
	while (map[i].hex)
	{
		if (i % 64)
			ft_putchar(' ');
		put_color(map[i].color);
		ft_putchar(map[i++].hex);
		ft_putchar(map[i++].hex);
		put_color(0);
		if (!(i % 64))
			ft_putchar('\n');
	}
}
