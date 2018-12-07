/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:56:52 by agissing          #+#    #+#             */
/*   Updated: 2018/11/24 14:06:28 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_count(char *tetri, char c)
{
	int		i;

	i = 0;
	while (*tetri)
		if (*tetri++ == c)
			i++;
	return (i);
}

int				ft_check(char *tetri)
{
	int		i;
	int		count;
	int		max;

	i = 0;
	max = 0;
	if (ft_count(tetri, '#') != 4 || ft_strlen(tetri) != 20 ||
		ft_count(tetri, '.') != 12)
		return (0);
	while (tetri[i])
	{
		count = 0;
		if (tetri[i] == '#')
		{
			(tetri[i + 1] == '#') ? count++ : 0;
			(i > 0 && tetri[i - 1] == '#') ? count++ : 0;
			(i / 5 != 3 && tetri[i + 5] == '#') ? count++ : 0;
			(i / 5 != 0 && tetri[i - 5] == '#') ? count++ : 0;
			if (!count)
				return (0);
			count > max ? (max = count) : 1;
		}
		if ((i + 1) % 5 == 0 && tetri[i] != '\n')
			return (0);
		i++;
	}
	if (max >= 2)
		return (1);
	return (0);
}
