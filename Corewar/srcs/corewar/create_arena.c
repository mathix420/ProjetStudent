/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:49:46 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/15 18:26:16 by trlevequ         ###   ########.fr       */
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
		map[i].bold_decount = 0;
	}
	map[i].hex = '\0';
}

t_arena	*init_arena(void)
{
	t_arena		*arena;
	int			*size_list;

	if ((arena = (t_arena *)malloc(sizeof(t_arena))) == NULL)
		ft_exit();
	if (!(size_list = (int *)malloc(sizeof(int))))
		ft_exit();
	*size_list = 1;
	init_map(arena->map);
	arena->cycle = 0;
	arena->dump = -1;
	arena->graphic = 0;
	arena->cycle_decount = CYCLE_TO_DIE;
	arena->cycle_to_die = CYCLE_TO_DIE;
	arena->total_process = 0;
	arena->total_lives = 0;
	arena->nb_checks = 0;
	arena->champion = NULL;
	arena->process = NULL;
	arena->cycle_per_sec = 50;
	arena->max_size_list = 1000;
	arena->size_list = size_list;
	arena->ncurses = NULL;
	arena->next = NULL;
	return (arena);
}

t_arena	*create_arena(int ac, char **av)
{
	int		champ;
	t_arena	*arena;
	t_map	*pos_champ;

	(void)ac;
	arena = init_arena();
	parsing_arguments(av, arena);
	arena->total_process = arena->nb_champs;
	champ = -1;
	while (++champ < arena->nb_champs)
	{
		pos_champ = arena->map + ((MEM_SIZE * 2) / arena->nb_champs) * champ;
		create_champ(av[arena->arg_champ[champ]], pos_champ, champ + 1, arena);
	}
	return (arena);
}
