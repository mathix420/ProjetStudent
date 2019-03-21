/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:04:59 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/20 16:28:00 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				champ_live(t_process *process, t_champion *champion,
				int last_alive)
{
	int	found_champ;

	found_champ = 0;
	while (champion)
	{
		if (champion->number == process->param[0].value)
		{
			champion->last_live = process->arena->cycle;
			champion->last_alive = last_alive;
			champion->period_live_nb++;
			print_live(process, champion);
			found_champ = 1;
		}
		champion = champion->next;
	}
	return (found_champ);
}

void			ft_live(t_process *process)
{
	int			found_champ;
	static int	last_cycle = 0;
	static int	last_alive = 0;

	if (last_cycle != process->arena->cycle)
	{
		last_alive = 0;
		last_cycle = process->arena->cycle;
	}
	else
		last_alive++;
	found_champ = champ_live(process, process->arena->champion, last_alive);
	if (!process->arena->graphic && !found_champ)
		ft_putstr("Un live a ete effectue sur un joueur qui n'existe pas\n");
	process->arena->total_lives++;
	process->alive = 1;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}
