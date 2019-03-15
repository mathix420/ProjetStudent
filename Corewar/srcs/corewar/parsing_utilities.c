/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:10:35 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/15 18:11:25 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		number_of_champion(int tab[4], int nb_champ)
{
	int	nb;
	int	i;

	if (nb_champ == 0)
		return (1);
	nb = 1;
	i = -1;
	while (++i < nb_champ)
	{
		if (nb == tab[i])
		{
			nb++;
			i = -1;
		}
	}
	return (nb);
}

int		ft_str_is_nbr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
