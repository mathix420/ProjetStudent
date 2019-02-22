/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:14:21 by agissing          #+#    #+#             */
/*   Updated: 2018/11/06 17:16:33 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		c;
	int		out;

	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else if (nb == 2)
		return (2);
	else
	{
		c = 2;
		out = 1;
		while (c <= nb)
			out *= c++;
		return (out);
	}
}
