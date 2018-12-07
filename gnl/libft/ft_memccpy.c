/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:09:59 by agissing          #+#    #+#             */
/*   Updated: 2018/11/07 16:47:56 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char *restrict)dst)[i] = ((char *restrict)src)[i];
		if ((char)c == ((char *restrict)src)[i])
			return (&dst[++i]);
		i++;
	}
	return (NULL);
}
