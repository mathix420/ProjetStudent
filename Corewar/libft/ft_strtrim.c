/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:33:10 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 16:52:04 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;

	if (s != NULL)
	{
		start = 0;
		end = ft_strlen(s) - 1;
		while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
			start++;
		while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && end != 0)
			end--;
		end++;
		if (start > end)
			return (ft_strnew(0));
		if ((str = ft_strsub(s, start, end - start)) == NULL)
			return (NULL);
		return (str);
	}
	return (NULL);
}
