/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:10:15 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/20 16:29:07 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_process_fork(t_process *process_father, int param, int restr)
{
	t_process	*process;
	int			i;
	int			idx;

	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		ft_exit();
	process->arena = process_father->arena;
	idx = pc_index(process_father, param, restr);
	process->pc = &process->arena->map[idx];
	process->alive = process_father->alive;
	process->valid_encodage = 1;
	process->cycle_decount = 0;
	process->index = 0;
	process->size_instruction = 0;
	process->color = process_father->color;
	process->carry = process_father->carry;
	i = -1;
	while (++i < REG_NUMBER)
		process->registre[i] = process_father->registre[i];
	process->next = process->arena->process;
	process->arena->process = process;
	process->arena->total_process++;
	get_current_instruction(process);
}

void	ft_fork(t_process *process)
{
	add_process_fork(process, process->param[0].value, 1);
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_lfork(t_process *process)
{
	add_process_fork(process, process->param[0].value, 0);
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}
