/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:01:03 by agissing          #+#    #+#             */
/*   Updated: 2018/11/06 15:23:14 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int		ft_strlen(char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*out;
	int		i;

	i = -1;
	if (!(out = malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (0);
	while (src[++i])
		out[i] = src[i];
	out[i] = '\0';
	return (out);
}
