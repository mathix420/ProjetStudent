/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:56:52 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/06 14:58:08 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "corewar.h"

void	check_process(t_process *process)
{
	if (process->cycle_decount > 1)
		process->cycle_decount--;
	else if (process->cycle_decount == 1)
	{
		get_param_instruction(process);
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

/*void	test(t_arena *arena)
{
	int		offset;

	offset = 2;
	printf("%p\n", arena->map);
	printf("%p\n", arena->map + 1);
	printf("%ld\n", (long int)arena->map);
	printf("%ld\n", ((long int)arena->map + offset) - (long int)arena->map);
	printf("%p\n", arena->map);
	printf("%p\n", tmp);
	arena->map + ((arena->pc + tmp) % MEM_SIZE)
}*/

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = create_arena(ac, av);
	//test(arena);
	corewar(arena);
	print_map(arena->map);
	//print_structure(*arena, arena->map);
	return (0);
}
