/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:09:50 by jnoe              #+#    #+#             */
/*   Updated: 2019/02/28 09:53:52 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_structure(t_arena arena, t_map *map)
{
	t_champion	*champion;
	t_process	*process;

	champion = arena.champion;
	ft_putstr("cycle: ");
	ft_putnbr(arena.cycle);
	ft_putchar('\n');
	ft_putstr("cycle_to_die: ");
	ft_putnbr(arena.cycle_to_die);
	ft_putstr("\n\n");
	ft_putstr("CHAMPIONS\n");
	while (champion)
	{
		ft_putstr("Name: ");
		ft_putstr(champion->name);
		ft_putstr("\n");
		ft_putstr("Number: ");
		ft_putnbr(champion->number);
		ft_putstr("\n");
		ft_putstr("Last live: ");
		ft_putnbr(champion->last_live);
		ft_putstr("\n");
		ft_putstr("Period live nb: ");
		ft_putnbr(champion->period_live_nb);
		ft_putstr("\n");
		ft_putstr("Process\n");
		process = champion->process;
		while (process)
		{
			ft_putstr("Pc: ");
			ft_putnbr((process->pc - map) / 2);
			ft_putstr("\n");
			ft_putstr("Cycle decount: ");
			ft_putnbr(process->cycle_decount);
			ft_putstr("\n");
			process = process->next;
		}
		champion = champion->next;
	}
}
