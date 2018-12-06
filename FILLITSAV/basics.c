/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:53:17 by agissing          #+#    #+#             */
/*   Updated: 2018/11/22 19:17:49 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void		ft_free_error(char **str)
{
	free(*str);
	ft_error();
}

void		ft_tetri_to_a(char **tetri, char a)
{
	int		i;

	i = 0;
	while ((*tetri)[i])
		if ((*tetri)[i] == '#' || i++ < 0)
			(*tetri)[i++] = a;
}

void		ft_putsoluce(char *grid, int cote)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		if (i > 0 && i % cote == 0)
			ft_putchar('\n');
		ft_putchar(grid[i]);
	}
}
