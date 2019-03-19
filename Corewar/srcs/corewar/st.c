/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:08:47 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/18 17:47:22 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

void	store_on_map(t_process *process, int param, int param2, int restr)
{
	int		pc_idx;
	char	str[9];
	int		i;
	t_map	*pos;

	pc_idx = pc_index(process, param, restr);
	pos = process->arena->map;
	convert_to_hexa_str(str, param2);
	i = -1;
	while (++i < 8)
	{
		pos[(pc_idx + i) % ((int)MEM_SIZE * 2)].hex = str[i];
		pos[(pc_idx + i) % ((int)MEM_SIZE * 2)].color = process->color;
		pos[(pc_idx + i) % ((int)MEM_SIZE * 2)].bold_decount = 50;
	}
}

void	ft_st(t_process *process)
{
	if (!check_registre(process->param, 2))
	{
		process->pc += process->size_instruction;
		return ;
	}
	if (process->param[1].type == T_REG)
		process->registre[process->param[1].value] = process->registre[
			process->param[0].value];
	else if (process->param[1].type == T_IND)
		store_on_map(process, process->param[1].value,
				process->registre[process->param[0].value - 1], 1);
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}

void	ft_sti(t_process *process)
{
	unsigned int	param2;
	unsigned int	param3;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	param2 = recup_param(process, 1, 1);
	param3 = recup_param(process, 2, 1);
	store_on_map(process, param2 + param3,
			process->registre[process->param[0].value - 1], 1);
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc
				- process->arena->map)) % ((int)MEM_SIZE * 2)];
}
