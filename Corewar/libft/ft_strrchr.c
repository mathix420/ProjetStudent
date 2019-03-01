/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:09:27 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/09 17:32:08 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int last;

	last = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (last == -1)
		return (NULL);
	return ((char *)s + last);
}
