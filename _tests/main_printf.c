/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:10:46 by agissing          #+#    #+#             */
/*   Updated: 2018/12/11 17:06:25 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char		nb;
	long double	dd;

	dd = 1.4;
	nb = 9;
	printf(" = %d\n", ft_printf("dede%Lf %10s", dd, "tete")); //precision .0
	printf(" = %d\n", printf("dada%Lf %10s", dd, "tete"));
	return (0);
}
