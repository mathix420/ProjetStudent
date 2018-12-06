/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:31:23 by agissing          #+#    #+#             */
/*   Updated: 2018/11/08 14:36:40 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2 && n--)
	{
		s1++;
		s2++;
	}
	if ((*s1 || *s2) && n > 0)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
