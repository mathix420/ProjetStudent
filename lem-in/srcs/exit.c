/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:22:35 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 20:16:42 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_exit(int error)
{
	write(1, "ERROR => ", 9);
	(error == 1) ? write(1, "No links\n", 8) : 1;
	(error == 2) ? write(1, "No start/end\n", 13) : 1;
	(error == 3) ? write(1, "Same start/end\n", 15) : 1;
	(error == 4) ? write(1, "Wrong ant number\n", 17) : 1;
	(error == 5) ? write(1, "No way\n", 7) : 1;
	exit(1);
}
