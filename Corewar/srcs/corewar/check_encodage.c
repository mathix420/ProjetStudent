/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_encodage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:53:24 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/15 16:31:43 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	conv_ocp_to_str(t_process *process, char str[], int size)
{
	int pc_idx;
	int str_idx;

	str_idx = -1;
	pc_idx = (int)(process->pc - process->arena->map);
	while (++str_idx < size)
		str[str_idx] = process->arena->map[(pc_idx++ + 2) % (MEM_SIZE * 2)].hex;
}

int		no_encodage_needed(t_process *process)
{
	if (!ft_strcmp(g_op_tab[process->index].name, "live") \
			|| !ft_strcmp(g_op_tab[process->index].name, "zjmp") \
			|| !ft_strcmp(g_op_tab[process->index].name, "fork") \
			|| !ft_strcmp(g_op_tab[process->index].name, "lfork"))
	{
		process->param[0].type = g_op_tab[process->index].encodage[0];
		process->size_instruction = (!process->index) ? 8 + 2 : 4 + 2;
		return (1);
	}
	return (0);
}

void	check_tab_encodage(t_process *process, int param, int type_param)
{
	if (!type_param || (g_op_tab[process->index].encodage[param]
				& type_param) != type_param)
		process->valid_encodage = 0;
	if (type_param == T_REG)
	{
		process->param[param].type = T_REG;
		process->size_instruction += 2;
	}
	else if (type_param == T_DIR)
	{
		process->param[param].type = T_DIR;
		process->size_instruction += (
				g_op_tab[process->index].direct_size) ? 4 : 8;
	}
	else if (type_param == T_IND)
	{
		process->param[param].type = T_IND;
		process->size_instruction += 4;
	}
}

void	check_encodage(t_process *process)
{
	int		encodage;
	char	str_hex[2];
	int		param;

	conv_ocp_to_str(process, str_hex, 2);
	encodage = hex_to_int(str_hex, "0123456789abcdef", 2);
	process->size_instruction = 4;
	param = -1;
	while (++param < g_op_tab[process->index].nb_param)
	{
		if ((INDIRECT >> (param * 2) & encodage) == (INDIRECT >> (param * 2)))
			check_tab_encodage(process, param, T_IND);
		else if ((REGISTRE >> (param * 2) & encodage)
				== (REGISTRE >> (param * 2)))
			check_tab_encodage(process, param, T_REG);
		else if ((DIRECT >> (param * 2) & encodage) == (DIRECT >> (param * 2)))
			check_tab_encodage(process, param, T_DIR);
		else
			check_tab_encodage(process, param, 0);
	}
}
