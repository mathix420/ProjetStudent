/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:10:46 by agissing          #+#    #+#             */
/*   Updated: 2018/12/08 18:12:40 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char	nb;
	float	dd;

	dd = -12.059;
	nb = 95;
	printf("sign :: %c\nexp :: %08x\n", (uint64_t)dd & (0x8 << 28) ? '-' : '+', *(unsigned int*)&dd);
	ft_printf("ft_printf\t %hhx %d\n", nb, nb);
	printf("printf   \t %hhx %d\n", nb, nb);
	return (0);
}
