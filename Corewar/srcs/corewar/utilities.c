/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:22:21 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/19 18:10:41 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

int		check_registre(t_param param[], int nb_params)
{
	int	i;

	i = -1;
	while (++i < nb_params)
	{
		if (param[i].type == T_REG && (param[i].value < 1
				|| param[i].value > REG_NUMBER))
			return (0);
	}
	return (1);
}

int		pc_index(t_process *process, int param, int restr)
{
	int		pc_idx;

	if (restr)
	{
		pc_idx = (int)(process->pc - process->arena->map)
			+ ((param * 2) % ((int)IDX_MOD * 2));
		if (pc_idx >= 0)
			pc_idx = pc_idx % ((int)MEM_SIZE * 2);
		else
			pc_idx = ((int)MEM_SIZE * 2) + (pc_idx % ((int)MEM_SIZE * 2));
	}
	else
	{
		pc_idx = (int)(process->pc - process->arena->map)
			+ ((param * 2) % ((int)MEM_SIZE * 2));
		if (pc_idx >= 0)
			pc_idx = pc_idx % ((int)MEM_SIZE * 2);
		else
			pc_idx = ((int)MEM_SIZE * 2) + (pc_idx % ((int)MEM_SIZE * 2));
	}
	return (pc_idx);
}

int		indirect_value(t_process *process, int param, int restr)
{
	int		pc_idx;
	char	str[9];
	int		i;
	t_map	*pos;

	pc_idx = pc_index(process, param, restr);
	pos = process->arena->map;
	i = -1;
	while (++i < 8)
		str[i] = pos[(pc_idx + i) % ((int)MEM_SIZE * 2)].hex;
	str[8] = '\0';
	return (hex_to_int(str, "0123456789abcdef", 8));
}

void	convert_to_hexa_str(char str[], int param)
{
	unsigned int	nb;
	int				i;
	char			base[17];

	ft_strcpy(base, "0123456789abcdef");
	nb = param;
	i = -1;
	while (++i < 8)
		str[i] = '0';
	i = 0;
	while (nb)
	{
		str[i] = base[nb % 16];
		i++;
		nb = nb / 16;
	}
	str[8] = '\0';
	ft_strrev(str);
}

int		recup_param(t_process *process, int idx, int restr)
{
	unsigned int	value;

	value = 0;
	if (process->param[idx].type == T_REG)
		value = process->registre[process->param[idx].value - 1];
	else if (process->param[idx].type == T_DIR)
		value = process->param[idx].value;
	else if (process->param[idx].type == T_IND)
		value = indirect_value(process, process->param[idx].value, restr);
	return (value);
}
