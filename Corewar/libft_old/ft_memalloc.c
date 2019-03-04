/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:27:16 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 16:48:45 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*mem;
	unsigned int	i;

	i = 0;
	if ((mem = (void *)malloc(size)) == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
