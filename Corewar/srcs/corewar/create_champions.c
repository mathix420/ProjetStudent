/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:08:42 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/01 14:40:35 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "corewar.h"

void		convert_to_hexa(unsigned char byte, t_map **map, int color)
{
	char	base[17];

	ft_strcpy(base, "0123456789abcdef");
	(*map)[0].hex = base[byte / 16 % 16];
	(*map)[1].hex = base[byte % 16];
	(*map)[0].color = color;
	(*map)[1].color = color;
	*map += 2;
}

t_process	*init_process(t_map *pc, t_champion *champion)
{
	t_process	*process;

	if ((process = (t_process *)malloc(sizeof(t_process))) == NULL)
		ft_exit();
	process->pc = pc;
	process->cycle_decount = 0;
	process->size_instruction = 0;
	process->idx_instruction = 0;
	process->champion = champion;
	process->next = NULL;
	return (process);
}

void		init_champion(char *name, int number, t_map *pc, t_arena *arena)
{
	t_champion	*champion;
	t_champion	*tmp_champ;

	if ((champion = (t_champion *)malloc(sizeof(t_champion))) == NULL)
		ft_exit();
	champion->name = ft_strdup(name);
	champion->number = number;
	champion->last_live = 0;
	champion->period_live_nb = 0;
	champion->nb_process = 1;
	champion->process = init_process(pc, champion);
	champion->arena = arena;
	champion->next = NULL;
	tmp_champ = arena->champion;
	while (tmp_champ && tmp_champ->next)
		tmp_champ = tmp_champ->next;
	if (!tmp_champ)
		arena->champion = champion;
	else
		tmp_champ->next = champion;
}

void		create_champ(char *file_name, t_map *map, int color, t_arena *arena)
{
	int				fd;
	unsigned char	byte;
	int				nb_bytes_read;
	t_map			*beg_champion;

	init_champion(file_name, color, map, arena);
	beg_champion = map;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_exit();
	if ((lseek(fd, 2192, SEEK_SET)) == -1)
		ft_exit();
	while ((nb_bytes_read = read(fd, &byte, 1)) > 0)
	{
		if (map - beg_champion > CHAMP_MAX_SIZE * 2)
			ft_exit();
		convert_to_hexa(byte, &map, color);
	}
	if ((nb_bytes_read = read(fd, &byte, 1)) == -1)
		ft_exit();
	close(fd);
}
