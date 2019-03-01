/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:32:49 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 16:51:45 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		j = 0;
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			str[i + j] = s2[j];
			j++;
		}
		return (str);
	}
	return (NULL);
}
