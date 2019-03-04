/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:41:03 by agissing          #+#    #+#             */
/*   Updated: 2018/11/09 18:40:03 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	unsigned int	nb;
	size_t			i;
	char			*str;

	i = 0;
	if (!(str = ft_strnew(ft_nblen(n))))
		return (NULL);
	nb = (n < 0 ? -n : n);
	while (nb > 0 || i == 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
		str[i] = '-';
	return (ft_strrev(str));
}
