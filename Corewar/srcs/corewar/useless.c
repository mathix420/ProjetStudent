/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:10:52 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/15 17:47:36 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

void	ft_aff(t_process *process)
{
	get_current_instruction(process);
	if (!process->arena->graphic)
		ft_putchar((process->param[0].value % 256));
	process->carry = (!process->param[0].value % 256) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_nothing(t_process *process)
{
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}
