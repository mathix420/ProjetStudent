/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:22:35 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 15:23:48 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_exit(int error)
{
	if (error != 3)
		write(1, "ERROR\n", 6);
	exit(1);
}

void			frexit(void *to_free, int error)
{
	to_free ? free(to_free) : 1;
	ft_exit(error);
}
