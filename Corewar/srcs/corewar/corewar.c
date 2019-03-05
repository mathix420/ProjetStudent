/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:47:29 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/05 18:54:27 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

void	get_current_instruction(t_process *process)
{
	char	str_hex[2];
	int		index;

	str_hex[0] = process->pc[0].hex;
	str_hex[1] = process->pc[1].hex;
	index = hex_to_int(str_hex, "0123456789abcdef", 2) - 1;
	process->index = (index >= 0 && index < 16) ? index : 16;
	process->valid_encodage = 1;
	if (process->index == 16)
	{
		process->cycle_decount = 1;
		process->size_instruction = 2;
	}
	else if (no_encodage_needed(process))
		process->cycle_decount = g_op_tab[index].duration;
	else
	{
		check_encodage(process);
		process->cycle_decount = (process->valid_encodage) \
			? g_op_tab[index].duration : 1;
	}
}

void	check_process(t_process *process)
{
	if (process->cycle_decount > 1)
		process->cycle_decount--;
	else if (process->cycle_decount == 1)
	{
		g_op_tab[process->index].function(process);
		get_current_instruction(process);
	}
	else if (process->cycle_decount == 0)
		get_current_instruction(process);
}

void	check_all_process(t_arena *arena)
{
	t_process	*process;

	process = arena->process;
	while (process)
	{
		check_process(process);
		process = process->next;
	}
}

int		corewar(t_arena *arena)
{
	while (arena->total_process)
	{
		check_all_process(arena);
		arena->cycle++;
		if (arena->cycle % arena->cycle_to_die == 0)
			break ;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = create_arena(ac, av);
	parsing_champ(av[1], arena->champion);
	//corewar(arena);
	//print_map(arena->map);
	//print_structure(*arena, arena->map);
	return (0);
}
