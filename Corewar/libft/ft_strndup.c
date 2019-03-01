/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:17:01 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 18:28:57 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	unsigned int		len;
	unsigned int		i;
	char				*dest;

	len = (n > ft_strlen(s)) ? ft_strlen(s) : n;
	if ((dest = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = s[i];
	dest[i] = '\0';
	return (dest);
}
