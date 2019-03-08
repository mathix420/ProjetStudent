/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:56:52 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/08 18:36:16 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "corewar.h"

void	ft_print_instruction(t_process *process)
{
	if (process->index == 16)
		return ;
	printf("instruction = %s\n", g_op_tab[process->index].name);
	for (int i = 0; i < g_op_tab[process->index].nb_param; i++)
	{
		printf("Param %d: ", i);
		if (process->param[i].type == T_REG)
			printf("REGISTRE:");
		else if (process->param[i].type == T_DIR)
			printf("DIRECT:");
		else if (process->param[i].type == T_IND)
			printf("INDIRECT:");
		printf("value = %d\n", process->param[i].value);
	}
	printf("\n\n");
}


void	check_process(t_process *process)
{
	if (process->cycle_decount > 1)
		process->cycle_decount--;
	else if (process->cycle_decount == 1)
	{
		get_param_instruction(process);
		//ft_print_instruction(process);
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
		print_graphic_corewar(arena);
		arena->cycle++;
		if (arena->cycle % arena->cycle_to_die == 0)
			kill_no_live_process(arena);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_arena		*arena;

	arena = create_arena(ac, av);
	init_graphic(arena);
	corewar(arena);
	usleep(100000);
	endwin();
	return (0);
}
