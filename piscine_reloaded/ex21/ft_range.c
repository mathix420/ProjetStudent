/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:26:56 by agissing          #+#    #+#             */
/*   Updated: 2018/11/06 15:36:06 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	else if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (i < max - min)
	{
		tab[i] = i + min;
		i++;
	}
	return (tab);
}
