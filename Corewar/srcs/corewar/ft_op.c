/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:58:25 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/07 14:14:37 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

void	ft_live(t_process *process)
{
	t_champion	*champion;

	champion = process->arena->champion;
	while (champion)
	{
		if (champion->number == process->param[0].value)
		{
			champion->last_live = process->arena->cycle;
			champion->period_live_nb++;
		}
		champion = champion->next;
	}
	process->alive = 1;
	process->pc += process->size_instruction;
	ft_putstr("Live\n");
}

void	ft_ld(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Ld\n");
}

void	ft_st(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("St\n");
}

void	ft_add(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Add\n");
}

void	ft_sub(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Sub\n");
}

void	ft_and(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("And\n");
}

void	ft_or(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Or\n");
}

void	ft_xor(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Xor\n");
}

void	ft_zjmp(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Zjmp\n");
}

void	ft_ldi(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Ldi\n");
}

void	ft_sti(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Sti\n");
}

void	ft_fork(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Fork\n");
}

void	ft_lld(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Lld\n");
}

void	ft_lldi(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Lldi\n");
}

void	ft_lfork(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Lfork\n");
}

void	ft_aff(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Aff\n");
}

void	ft_nothing(t_process *process)
{
	process->pc += process->size_instruction;
	//ft_putstr("Nothing\n");
}
