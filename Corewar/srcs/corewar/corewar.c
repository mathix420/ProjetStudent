/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:38:59 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/01 16:22:58 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_encodage(t_process *process)
{
	int		encodage;
	char	str_hex[2];
	
	//sauf lfork, fork, live, zjmp
	str_hex[0] = process->pc[2].hex;
	str_hex[1] = process->pc[3].hex;
	encodage = hex_to_int(str_hex, "0123456789abcdef", 2);
	
	return (0);
}

void	get_op_instruction(t_process *process)
{
	char	str_hex[2];
	int		index;

	str_hex[0] = process->pc[0].hex;
	str_hex[1] = process->pc[1].hex;
	index = hex_to_int(str_hex, "0123456789abcdef", 2) - 1;
	index = (index >= 0 && index < 16) ? index : 16;
	process->idx_instruction = index;
	if (check_encodage(process))
		process->cycle_decount = op_tab[index].duration;
}

void	check_process(t_process *process)
{
	if (!process->cycle_decount)
		get_op_instruction(process);
	else if (process->cycle_decount > 1)
		process->cycle_decount--;
	else
		op_tab[process->idx_instruction].function(process->champion->arena);
}

void	check_all_process(t_arena *arena)
{
	t_champion	*champion;
	t_process	*process;

	champion = arena->champion;
	while (champion)
	{
		process = champion->process;
		while (process)
		{
			check_process(process);
			process = process->next;
		}
		champion = champion->next;
	}
}

int		corewar(t_arena *arena)
{
	while (arena->total_process)
	{
		ft_putstr("It's now cycle: ");
		ft_putnbr(arena->cycle);
		ft_putchar('\n');
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
	corewar(arena);
	//print_map(arena->map);
	//print_structure(*arena, arena->map);
	return (0);
}
