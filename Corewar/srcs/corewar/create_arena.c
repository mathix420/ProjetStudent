/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:01:52 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/05 15:23:36 by trlevequ         ###   ########.fr       */
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
	arena->process = NULL;
	return (arena);
}

t_arena	*create_arena(int ac, char **av)
{
	int		champ;
	t_arena	*arena;
	t_map	*pos_champ;

	if (ac == 1 || ac > 5)
		ft_exit();
	arena = init_arena(ac - 1);
	champ = 0;
	while (++champ < ac)
	{
		pos_champ = arena->map + ((MEM_SIZE * 2) / (ac - 1)) * (champ - 1);
		create_champ(av[champ], pos_champ, champ, arena);
	}
	return (arena);
}
