/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:53:55 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/20 16:55:57 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_str(int n)
{
	int c;

	c = 0;
	if (n < 0)
		c++;
	while (n != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

static void		reverse_str(char *str)
{
	int		i;
	int		len;
	int		j;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	while (i < len / 2)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		sign;

	i = 0;
	if ((sign = 1) && (n < 0))
		(sign = -1);
	if ((str = ft_strnew(len_str(n))) == NULL)
		return (NULL);
	if (n == 0)
	{
		if ((str = ft_strnew(1)) == NULL)
			return (NULL);
		str[i] = '0';
	}
	while (n != 0)
	{
		str[i] = (sign * (n % 10) + 48);
		n = n / 10;
		i++;
	}
	if (sign == -1)
		str[i] = '-';
	reverse_str(str);
	return (str);
}
