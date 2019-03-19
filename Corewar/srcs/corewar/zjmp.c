/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:08:10 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/18 17:46:40 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

void	ft_zjmp(t_process *process)
{
	int				pc_idx;
	short int		param;

	param = process->param[0].value;
	if (process->carry)
	{
		pc_idx = (int)(process->pc - process->arena->map)
			+ ((param * 2) % ((int)IDX_MOD * 2));
		if (pc_idx >= 0)
			pc_idx = pc_idx % ((int)MEM_SIZE * 2);
		else
			pc_idx = ((int)MEM_SIZE * 2) + (pc_idx % ((int)MEM_SIZE * 2));
		process->pc = &process->arena->map[pc_idx];
	}
	else
	{
		process->pc += process->size_instruction;
		process->pc = &process->arena->map[((int)(process->pc
					- process->arena->map)) % ((int)MEM_SIZE * 2)];
	}
}
