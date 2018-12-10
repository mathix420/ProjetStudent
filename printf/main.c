/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:10:46 by agissing          #+#    #+#             */
/*   Updated: 2018/12/10 12:22:58 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char		nb;
	long double	dd;

	dd = -9999912.0599999999999999999999999;
	nb = 950;
	printf(" = %d\n", ft_printf("%d %hx %100p", nb, nb, &dd));
	printf(" = %d\n", printf("%d %hx %100p", nb, nb, &dd));
	return (0);
}
