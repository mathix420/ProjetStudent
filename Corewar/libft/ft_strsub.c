/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:32:14 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 16:51:32 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	len_s;

	if (s != NULL)
	{
		len_s = ft_strlen(s);
		i = 0;
		if ((str = ft_strnew(len)) == NULL)
			return (NULL);
		while (i < len && start < len_s && s[start + i] != '\0')
		{
			str[i] = s[start + i];
			i++;
		}
		return (str);
	}
	return (NULL);
}
