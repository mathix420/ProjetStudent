/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:09:42 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/22 11:18:26 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int i;
	int j;
	int len_aiguille;

	i = 0;
	if ((len_aiguille = ft_strlen(aiguille)) == 0)
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] != '\0')
	{
		j = 0;
		while (meule_de_foin[i + j] != '\0'
				&& meule_de_foin[i + j] == aiguille[j])
			j++;
		if (j == len_aiguille)
			return ((char*)meule_de_foin + i);
		i++;
	}
	return (NULL);
}
