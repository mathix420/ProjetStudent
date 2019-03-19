/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:04:59 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/18 17:49:33 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

static void		print_live(t_process *process, t_champion *champion)
{
	if (!process->arena->graphic)
	{
		ft_putstr("Un processus dit que le joueur ");
		ft_putnbr(champion->number);
		ft_putstr("(");
		ft_putstr(champion->name);
		ft_putstr(") est en vie\n");
	}
}

void			ft_live(t_process *process)
{
	t_champion	*champion;
	int			found_champ;

	champion = process->arena->champion;
	found_champ = 0;
	while (champion)
	{
		if (champion->number == process->param[0].value)
		{
			champion->last_live = process->arena->cycle;
			champion->period_live_nb++;
			print_live(process, champion);
			found_champ = 1;
		}
		champion = champion->next;
	}
	if (!process->arena->graphic && !found_champ)
		ft_putstr("Un live a ete effectue sur un joueur qui n'existe pas\n");
	process->arena->total_lives++;
	process->alive = 1;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}
