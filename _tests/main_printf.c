/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:10:46 by agissing          #+#    #+#             */
/*   Updated: 2018/12/11 17:47:21 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char		nb;
	long double	dd;

	dd = 16888565288.36645645;
	nb = 9;
	printf(" = %d\n", ft_printf("dede%.30Lf %10s %5d %-5%", dd, "tete", 1));
	printf(" = %d\n", printf("dada%.30Lf %10s %5d %-5%", dd, "tete", 1));
	return (0);
}
