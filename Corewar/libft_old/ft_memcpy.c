/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:23:38 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/12 13:14:42 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	void			*pt;

	pt = dest;
	i = 0;
	while (i < n)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		dest++;
		src++;
		i++;
	}
	return (pt);
}
