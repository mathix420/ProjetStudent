/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cycle_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:28:05 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/20 14:10:51 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

void	copy_tab_process(t_process *new_process, t_process *src_process)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		new_process->registre[i] = src_process->registre[i];
	i = -1;
	while (++i < 3)
		new_process->param[i] = src_process->param[i];
}

void	copy_data_process(t_process *new_process, t_process *src_process)
{
	new_process->alive = src_process->alive;
	new_process->valid_encodage = src_process->encodage;
	new_process->encodage = src_process->encodage;
	new_process->cycle_decount = src_process->cycle_decount;
	new_process->index = src_process->index;
	new_process->size_instruction = src_process->size_instruction;
	new_process->color = src_process->color;
	new_process->carry = src_process->carry;
}

void	copy_processes(t_arena *arena)
{
	t_process		*src_process;
	t_process		*new_process;
	t_process		*prev_process;

	src_process = arena->next->process;
	while (src_process)
	{
		if (!(new_process = (t_process *)malloc(sizeof(t_process))))
			ft_exit();
		new_process->pc = arena->map + (src_process->pc - arena->next->map);
		copy_tab_process(new_process, src_process);
		copy_data_process(new_process, src_process);
		new_process->arena = arena;
		if (!arena->process)
			arena->process = new_process;
		else
			prev_process->next = new_process;
		prev_process = new_process;
		src_process = src_process->next;
	}
	new_process->next = NULL;
}
