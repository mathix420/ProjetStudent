/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:10:33 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/07 17:08:29 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_pow(int nb, int pui)
{
	if (pui < 0)
		return (0);
	if (pui == 0)
		return (1);
	return (nb * ft_pow(nb, pui - 1));
}

int		convert_to_int(unsigned char *str)
{
	int i;
	int nbr;

	i = -1;
	nbr = 0;
	while (++i < 4)
		nbr += str[i] * ft_pow(256, 4 - i - 1);
	return (nbr);
}

int		hex_to_int(char *str, char *base, int len)
{
	int		nb;
	int		i;
	int		j;

	nb = 0;
	i = -1;
	while (++i < len)
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		nb += j * ft_pow(ft_strlen(base), len - i - 1);
	}
	return (nb);
}
