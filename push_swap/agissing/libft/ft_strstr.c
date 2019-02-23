/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:08:23 by agissing          #+#    #+#             */
/*   Updated: 2018/11/08 13:26:18 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0' && haystack[i + j - 1] == needle[j - 1])
				return ((char *)(&haystack[i]));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
