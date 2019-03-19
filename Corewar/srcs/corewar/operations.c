/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:07:12 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/19 19:09:10 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_add(t_process *process)
{
	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
		return ;
	}
	process->registre[process->param[2].value - 1] = process->registre[
		process->param[0].value - 1]
			+ process->registre[process->param[1].value - 1];
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_sub(t_process *process)
{
	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
		return ;
	}
	process->registre[process->param[2].value - 1] = process->registre[
		process->param[0].value - 1]
			- process->registre[process->param[1].value - 1];
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_and(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
		return ;
	}
	param1 = recup_param(process, 0, 1);
	param2 = recup_param(process, 1, 1);
	process->registre[process->param[2].value - 1] = param1 & param2;
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_or(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
		return ;
	}
	param1 = recup_param(process, 0, 1);
	param2 = recup_param(process, 1, 1);
	process->registre[process->param[2].value - 1] = param1 | param2;
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
		- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_xor(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
		return ;
	}
	param1 = recup_param(process, 0, 1);
	param2 = recup_param(process, 1, 1);
	process->registre[process->param[2].value - 1] = param1 ^ param2;
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
		- process->arena->map)) % ((int)MEM_SIZE * 2)];
}
