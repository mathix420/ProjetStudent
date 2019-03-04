/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:29:56 by agissing          #+#    #+#             */
/*   Updated: 2018/11/07 16:44:19 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*in;

	in = dst;
	if (dst < src)
		while ((size_t)(dst - in) < len)
			*(char*)dst++ = *(char*)src++;
	else
		while (len-- > 0)
			((char*)dst)[len] = ((char*)src)[len];
	return (in);
}
