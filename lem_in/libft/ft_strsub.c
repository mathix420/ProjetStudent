/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:54:48 by agissing          #+#    #+#             */
/*   Updated: 2019/02/23 14:26:58 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*out;

	i = 0;
	if (!s)
		return (NULL);
	if (!(out = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	return (out);
}
