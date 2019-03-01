/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:02:27 by trlevequ          #+#    #+#             */
/*   Updated: 2019/02/28 18:07:18 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_op_tab(t_arena *arena)
{
	int i;

	i = 0;
	while (i < 17)
	{
		ft_putstr("Name:");
		ft_putstr(arena->op_tab[i].name);
		ft_putchar('\n');
		ft_putstr("Duration:");
		ft_putnbr(arena->op_tab[i].duration);
		ft_putstr("\n\n");
		++i;
	}
}
