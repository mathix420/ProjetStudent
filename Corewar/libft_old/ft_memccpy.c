/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:23:22 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/19 16:52:23 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && *(char *)src != (char)c)
	{
		*(char*)dest = *(char*)src;
		dest++;
		src++;
		i++;
	}
	if (i < n && *(char *)src == (char)c)
	{
		*(char*)dest = *(char*)src;
		return (dest + 1);
	}
	return (NULL);
}
