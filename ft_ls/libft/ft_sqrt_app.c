/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_app.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:33:15 by kemartin          #+#    #+#             */
/*   Updated: 2018/12/11 14:33:19 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt_app(int nb)
{
	int		s;

	s = 0;
	while (s * s >= 0 && s * s < nb)
		s++;
	return (s);
}