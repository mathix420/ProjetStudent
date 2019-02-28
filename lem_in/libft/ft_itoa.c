/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:59:05 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 12:48:18 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	abs;
	unsigned int	tmp;

	len = (n < 0) ? 2 : 1;
	abs = (n < 0) ? -n : n;
	tmp = abs;
	while (tmp > 9)
	{
		len++;
		tmp /= 10;
	}
	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len--] = '\0';
	while (abs > 9)
	{
		s[len--] = (abs % 10) + 48;
		abs /= 10;
	}
	s[len] = (abs % 10) + 48;
	if (n < 0)
		s[--len] = '-';
	return (s);
}
