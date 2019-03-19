/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:06:01 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/18 17:49:56 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

void	ft_ld(t_process *process)
{
	unsigned int value;

	if (!check_registre(process->param, 2))
	{
		process->pc += process->size_instruction;
		return ;
	}
	value = recup_param(process, 0, 1);
	process->registre[process->param[1].value - 1] = value;
	process->carry = (!value) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_ldi(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	param1 = recup_param(process, 0, 1);
	param2 = recup_param(process, 1, 1);
	process->registre[process->param[2].value - 1] = indirect_value(
			process, param1 + param2, 1);
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_lld(t_process *process)
{
	unsigned int value;

	if (!check_registre(process->param, 2))
	{
		process->pc += process->size_instruction;
		return ;
	}
	value = recup_param(process, 0, 0);
	process->registre[process->param[1].value - 1] = value;
	process->carry = (!value) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_lldi(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	param1 = recup_param(process, 0, 0);
	param2 = recup_param(process, 1, 0);
	process->registre[process->param[2].value - 1] = indirect_value(
			process, param1 + param2, 0);
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}
