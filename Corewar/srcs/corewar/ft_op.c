/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:58:25 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/11 15:49:34 by jnoe             ###   ########.fr       */
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
		if (param[i].type == T_REG && (param[i].value < 1 || param[i].value > REG_NUMBER))
			return (0);
	}
	return (1);
}

int		indirect_value(t_process *process, int ind)
{
	int pc_idx;
	char str[9];
	int i;
	t_map *pos;

	pc_idx = ((int)(process->pc - process->arena->map) + (ind * 2)) % (MEM_SIZE * 2);
	pos = process->arena->map;
	i = -1;
	while (++i < 8)
		str[i] = pos[(pc_idx + i) % (MEM_SIZE * 2)].hex;
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

void	store_on_map(t_process *process, int ind, int param)
{
	int pc_idx;
	char str[9];
	int i;
	t_map *pos;

	pc_idx = ((int)(process->pc - process->arena->map) + (ind * 2)) % (MEM_SIZE * 2);
	pos = process->arena->map;
	convert_to_hexa_str(str, param);
	/*ft_putendl(str);
	ft_putnbr(pc_idx);
	ft_putendl("");*/
	i = -1;
	while (++i < 8)
	{
		pos[(pc_idx + i) % (MEM_SIZE * 2)].hex = str[i];
		pos[(pc_idx + i) % (MEM_SIZE * 2)].color = process->color;
		pos[(pc_idx + i) % (MEM_SIZE * 2)].bold_decount = 50;
	}
}

int		recup_param(t_process *process, int idx)
{
	unsigned int	value;

	value = 0;
	if (process->param[idx].type == T_REG)
		value = process->registre[process->param[idx].value - 1];
	else if (process->param[idx].type == T_DIR)
		value = process->param[idx].value;
	else if (process->param[idx].type == T_IND)
		value = indirect_value(process, process->param[idx].value);
	return (value);
}


void	ft_live(t_process *process)
{
	t_champion	*champion;
	int			found_champ;

	champion = process->arena->champion;
	found_champ = 0;
	while (champion)
	{
		if (champion->number == process->param[0].value)
		{
			champion->last_live = process->arena->cycle;
			champion->period_live_nb++;
			//ft_putstr("Un processus dit que le joueur ");
			//ft_putnbr(champion->number);
			//ft_putstr("(");
			//ft_putstr(champion->name);
			//ft_putstr(") est en vie\n");
			found_champ = 1;
		}
		champion = champion->next;
	}
	//if (!found_champ)
		//ft_putstr("Un live a ete effectue sur un joueur qui n'existe pas\n");
	process->alive = 1;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_ld(t_process *process)
{
	unsigned int value;

	if (!check_registre(process->param, 2))
	{
		process->pc += process->size_instruction;
		return ;
	}
	value = recup_param(process, 0);
	process->registre[process->param[1].value - 1] = value;
	process->carry = (!value) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_st(t_process *process)
{
	if (!check_registre(process->param, 2))
	{
		process->pc += process->size_instruction;
		return ;
	}
	if (process->param[1].type == T_REG)
		process->registre[process->param[1].value] = process->registre[process->param[0].value];
	else if (process->param[1].type == T_IND)
		store_on_map(process, process->param[1].value, process->registre[process->param[0].value - 1]);
	process->carry = (!process->param[0].value) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_add(t_process *process)
{
	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	process->registre[process->param[2].value - 1] = process->registre[process->param[0].value - 1] + process->registre[process->param[1].value - 1];
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_sub(t_process *process)
{
	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	process->registre[process->param[2].value - 1] = process->registre[process->param[0].value - 1] - process->registre[process->param[1].value - 1];
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_and(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	param1 = recup_param(process, 0);
	param2 = recup_param(process, 1);
	process->registre[process->param[2].value - 1] = param1 & param2;
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_or(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	param1 = recup_param(process, 0);
	param2 = recup_param(process, 1);
	process->registre[process->param[2].value - 1] = param1 | param2;
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_xor(t_process *process)
{
	unsigned int	param1;
	unsigned int	param2;

	if (!check_registre(process->param, 3))
	{
		process->pc += process->size_instruction;
		return ;
	}
	param1 = recup_param(process, 0);
	param2 = recup_param(process, 1);
	process->registre[process->param[2].value - 1] = param1 ^ param2;
	process->carry = (!process->registre[process->param[2].value - 1]) ? 1 : 0;
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_zjmp(t_process *process)
{
	if (process->carry)
		process->pc += process->param[0].value;
	else
		process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
}

void	ft_ldi(t_process *process)
{
/*	unsigned int	value;
	unsigned int	res;
	if (!check_registre(process->param, 2))
	{
		process->pc += process->size_instruction;
		return ;
	}
	if (process->param[0].type == T_DIR)
		res = process->param[0].value;
	else if (process->param[0].type == T_REG)
		res = process->registre[process->param[0].value - 1];
	else
		res = 
	value = indirect_value(process, res);
	process->registre[process->param[3].value - 1] = value;
	process->carry = (!value) ? 1 : 0;*/
	process->pc += process->size_instruction;
	process->pc = &process->arena->map[((int)(process->pc - process->arena->map)) % (MEM_SIZE * 2)];
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
