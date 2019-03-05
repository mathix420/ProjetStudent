/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:58:12 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/05 19:15:37 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"

void	ft_exit_parsing(int error, char *file_name)
{
	if (error == 0)
		ft_putstr_fd("Error read failed\n", 2);
	else if (error == 1)
		ft_putstr_fd("Error allocation failed\n", 2);
	else if (error == 2)
		ft_putstr_fd("Error open failed\n", 2);
	else if (error == 3)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" has an invalid header\n", 2);
	}
	else if (error == 4)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" has a code size that differ \
				from what its header says\n", 2);
	}
	exit(0);
}

void	ft_exit_size(int error, char *file_name, int size)
{
	if (error == 5)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" is too small to be a champion\n", 2);
	}
	else if (error == 6)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" has a too large code (", 2);
		ft_putnbr_fd(size, 2);
		ft_putstr_fd(" bytes > 682 bytes)\n", 2);
	}
	exit(0);
}

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
