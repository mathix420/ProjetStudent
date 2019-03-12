/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:18:07 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/11 17:08:36 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "corewar.h"

void	convert_to_hexa(unsigned char byte, t_map **map, int color)
{
	char	base[17];

	ft_strcpy(base, "0123456789abcdef");
	(*map)[0].hex = base[byte / 16 % 16];
	(*map)[1].hex = base[byte % 16];
	(*map)[0].color = color;
	(*map)[1].color = color;
	*map += 2;
}

void	add_process_from_player(t_arena *arena, t_map *pc, int nbr, int color)
{
	t_process	*process;
	int			i;

	i = 0;
	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		ft_exit();
	process->pc = pc;
	process->alive = 0;
	process->valid_encodage = 1;
	process->cycle_decount = 0;
	process->index = 0;
	process->size_instruction = 0;
	process->arena = arena;
	process->registre[i] = nbr;
	process->color = color;
	process->carry = 0;
	while (++i < REG_NUMBER)
		process->registre[i] = 0;
	process->next = arena->process;
	arena->process = process;
}

void	init_champion(char *name, int color, t_map *pc, t_arena *arena)
{
	t_champion	*champion;
	t_champion	*tmp_champ;

	if ((champion = (t_champion *)malloc(sizeof(t_champion))) == NULL)
		ft_exit();
	parsing_champ(name, champion);
	champion->number = -arena->number_champs[color - 1];
	champion->last_live = 0;
	champion->period_live_nb = 0;
	champion->color = color;
	champion->arena = arena;
	champion->next = NULL;
	tmp_champ = arena->champion;
	while (tmp_champ && tmp_champ->next)
		tmp_champ = tmp_champ->next;
	if (!tmp_champ)
		arena->champion = champion;
	else
		tmp_champ->next = champion;
	add_process_from_player(arena, pc, champion->number, color);
}

void	create_champ(char *file_name, t_map *map, int color, t_arena *arena)
{
	int				fd;
	unsigned char	byte;
	int				nb_bytes_read;
	t_map			*beg_champion;

	init_champion(file_name, color, map, arena);
	beg_champion = map;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_exit();
	if ((lseek(fd, 16 + PROG_NAME_LENGTH + COMMENT_LENGTH, SEEK_SET)) == -1)
		ft_exit();
	while ((nb_bytes_read = read(fd, &byte, 1)) > 0)
		convert_to_hexa(byte, &map, color);
	if ((nb_bytes_read = read(fd, &byte, 1)) == -1)
		ft_exit();
	close(fd);
}
