/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:55:07 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/25 16:25:27 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(s);
	if ((dest = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}
