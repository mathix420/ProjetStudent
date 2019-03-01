/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:28:52 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/19 17:00:59 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && *(char *)s != (char)c)
	{
		s++;
		i++;
	}
	if (i < n && *(char *)s == (char)c)
		return ((char *)s);
	return (NULL);
}
