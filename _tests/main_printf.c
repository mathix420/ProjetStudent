/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:10:46 by agissing          #+#    #+#             */
/*   Updated: 2018/12/11 18:14:30 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char		nb;
	long double	dd;

	dd = 16888565288.36645645;
	nb = 9;
	printf(" = %d\n", ft_printf("% 5%", nb));
	printf(" = %d\n", printf("% 5%", nb));
	return (0);
}
