/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:09:12 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 16:48:06 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t len)
{
	unsigned int i;
	unsigned int j;
	unsigned int len_aiguille;

	i = 0;
	if ((len_aiguille = ft_strlen(aiguille)) == 0)
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] != '\0' && len >= (i + len_aiguille))
	{
		j = 0;
		while (meule_de_foin[i + j] != '\0'
				&& meule_de_foin[i + j] == aiguille[j])
			j++;
		if (j == len_aiguille)
			return ((char *)meule_de_foin + i);
		i++;
	}
	return (NULL);
}
