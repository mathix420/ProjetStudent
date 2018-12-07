/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:34:29 by agissing          #+#    #+#             */
/*   Updated: 2018/12/07 15:00:03 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getminlength_or_precision(char *in, infos_t *infos)
{
	while (*in && !ft_isdigit(*in) && *in != '.')
		in++;
	infos->data &= ~12;
	(ft_isdigit(*in)) ? infos->data |= 8 :
		(*in == '.') ? infos->data |= 4 : 0;
	
}

void	ft_getprefix(char *in, uint32_t *data)
{
	in = "";
	data = 0;
}

void	ft_getoptions(char *in, uint32_t *data)
{
	in = "";
	data = 0;
}

infos_t	*ft_getinfos(char *input)
{
	infos_t		*infos;

	if (!(infos = malloc(sizeof(infos_t))))
		return (NULL);
	ft_getminlength_or_precision(input, infos);
	ft_getprefix(input, &(infos->data));
	ft_getoptions(input, &(infos->data));
	return (infos);
}
