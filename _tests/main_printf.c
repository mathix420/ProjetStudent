/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:10:46 by agissing          #+#    #+#             */
/*   Updated: 2018/12/15 15:28:53 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	/*
	ft_printf("%%\\n");// leaks
	ft_printf("%100.10d\n", 10000);
	printf("%100.10d\n", 10000);
	ft_printf("%s%s%s", "test\n", "test\n", "test\n");
	ft_printf("%jd\\n", 9223372036854775807);
	ft_printf("%zd\\n", 4294967295);
	ft_printf("%\\n");
	ft_printf("%U\\n", 4294967295);
	ft_printf("%S\\n", L"ݗݜशব");
	ft_printf("%s%s\\n", "test", "test");*/
	int		i;

	i = 0;
	printf("=%d\n", ft_printf("%30p  test", &i));
	printf("=%d\n", printf("%30p  test", &i));
	return (0);
}
