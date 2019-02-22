/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:47:05 by agissing          #+#    #+#             */
/*   Updated: 2018/11/05 15:47:06 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		a;
	int		c;

	a = 2;
	c = nb / 2;
	while (a <= c)
	{
		if (a * a == nb)
			return (a);
		a++;
	}
	return (0);
}
