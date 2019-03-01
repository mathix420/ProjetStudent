/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:01:52 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/01 09:17:27 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "corewar.h"

void	init_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE * 2)
	{
		map[i].hex = '0';
		map[i].color = 0;
	}
	map[i].hex = '\0';
}

t_arena	*init_arena(int nb_champ)
{
	t_arena		*arena;

	if ((arena = (t_arena *)malloc(sizeof(t_arena))) == NULL)
		ft_exit();
	init_map(arena->map);
	arena->cycle = 0;
	arena->cycle_to_die = CYCLE_TO_DIE;
	arena->total_process = nb_champ;
	arena->champion = NULL;
	return (arena);
}

void	init_op(t_arena *arena, void (*f)(t_arena *arena),
		char *name, int duration)
{
	static int	position = 0;

	arena->op_tab[position].name = ft_strdup(name);
	arena->op_tab[position].duration = duration;
	arena->op_tab[position].op_function = f;
	position++;
}

void	init_op_tab(t_arena *arena)
{
	init_op(arena, ft_live, "live", 10);
	init_op(arena, ft_ld, "ld", 5);
	init_op(arena, ft_st, "st", 5);
	init_op(arena, ft_add, "add", 10);
	init_op(arena, ft_sub, "sub", 10);
	init_op(arena, ft_and, "and", 6);
	init_op(arena, ft_or, "or", 6);
	init_op(arena, ft_xor, "xor", 6);
	init_op(arena, ft_zjmp, "zjmp", 20);
	init_op(arena, ft_ldi, "ldi", 25);
	init_op(arena, ft_sti, "sti", 25);
	init_op(arena, ft_fork, "fork", 800);
	init_op(arena, ft_lld, "lld", 10);
	init_op(arena, ft_lldi, "lldi", 50);
	init_op(arena, ft_lfork, "lfork", 1000);
	init_op(arena, ft_aff, "aff", 2);
	init_op(arena, ft_nothing, "nothing", 0);
}

t_arena	*create_arena(int ac, char **av)
{
	int		champ;
	t_arena	*arena;
	t_map	*pos_champ;

	if (ac == 1 || ac > 5)
		ft_exit();
	arena = init_arena(ac - 1);
	init_op_tab(arena);
	champ = 0;
	while (++champ < ac)
	{
		pos_champ = arena->map + ((MEM_SIZE * 2) / (ac - 1)) * (champ - 1);
		create_champ(av[champ], pos_champ, champ, arena);
	}
	return (arena);
}
