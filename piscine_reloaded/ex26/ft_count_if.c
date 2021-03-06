/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:03:17 by agissing          #+#    #+#             */
/*   Updated: 2018/11/06 16:39:39 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (tab[i])
		if (f(tab[i++]))
			c++;
	return (c);
}
