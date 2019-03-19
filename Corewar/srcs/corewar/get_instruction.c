/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:11:20 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/18 17:44:08 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	conv_op_to_str(t_process *process, t_map *pc, char str[], int size)
{
	int pc_idx;
	int str_idx;
	
	str_idx = -1;
	pc_idx = (int)(pc - process->arena->map);
	while (++str_idx < size)
		str[str_idx] = process->arena->map[pc_idx++ % (MEM_SIZE * 2)].hex;
}

void		get_param_instruction(t_process *process)
{
	int		idx_param;
	t_map	*tmp_pc;
	char	str[8];
	char	hex[17];
	int		size_param;

	ft_strcpy(hex, "0123456789abcdef");
	tmp_pc = (process->encodage) ? process->pc + 4 : process->pc + 2;
	idx_param = -1;
	while (++idx_param < g_op_tab[process->index].nb_param)
	{
		if (process->param[idx_param].type == T_REG)
			size_param = 2;
		else if (process->param[idx_param].type == T_DIR)
			size_param = (g_op_tab[process->index].direct_size) ? 4 : 8;
		else if (process->param[idx_param].type == T_IND)
			size_param = 4;
		conv_op_to_str(process, tmp_pc, str, size_param);
		process->param[idx_param].value = hex_to_int(str, hex, size_param);
		tmp_pc += size_param;
	}
}

void		get_current_instruction(t_process *process)
{
	char	str_hex[2];
	int		index;

	conv_op_to_str(process, process->pc, str_hex, 2);
	index = hex_to_int(str_hex, "0123456789abcdef", 2) - 1;
	process->index = (index >= 0 && index < 16) ? index : 16;
	process->encodage = 0;
	if (process->index == 16)
	{
		process->cycle_decount = 1;
		process->size_instruction = 2;
	}
	else if (no_encodage_needed(process))
		process->cycle_decount = g_op_tab[index].duration;
	else
	{
		process->encodage = 1;
		process->cycle_decount = g_op_tab[index].duration;
	}
}
