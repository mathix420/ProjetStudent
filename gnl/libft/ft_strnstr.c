/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:38:44 by agissing          #+#    #+#             */
/*   Updated: 2018/11/08 14:12:56 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j]
				&& (i + j) < len)
				j++;
			if (needle[j] == '\0' && haystack[i + j - 1] == needle[j - 1])
				return ((char *)(&haystack[i]));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
