/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cycle_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:28:05 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/15 17:31:17 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "corewar.h"

void	create_new_arena(t_arena **arena)
{
	t_arena *new_elmt;

	if (!(new_elmt = (t_arena *)malloc(sizeof(t_arena))))
		ft_exit();
	if ((*(*arena)->size_list) == (*arena)->max_size_list)
		delete_last_arena(*arena);
	(*(*arena)->size_list)++;
	new_elmt->next = *arena;
	new_elmt->process = NULL;
	new_elmt->champion = NULL;
	*arena = new_elmt;
}

void	copy_map(t_arena *arena)
{
	t_arena *elmt_src;
	int             i;

	elmt_src = arena->next;
	i = -1;
	while (++i < MEM_SIZE * 2)
		arena->map[i] = elmt_src->map[i];
}

void	copy_simple_data(t_arena *arena)
{
	t_arena *elmt_src;

	elmt_src = arena->next;
	arena->nb_champs = elmt_src->nb_champs;
	arena->total_process = elmt_src->total_process;
	arena->total_lives = elmt_src->total_lives;
	arena->nb_checks = elmt_src->nb_checks;
	arena->cycle = elmt_src->cycle;
	arena->cycle_to_die = elmt_src->cycle_to_die;
	arena->cycle_decount = elmt_src->cycle_decount;
	arena->cycle_per_sec = elmt_src->cycle_per_sec;
	arena->graphic = elmt_src->graphic;
	arena->ncurses = elmt_src->ncurses;
	arena->max_size_list = elmt_src->max_size_list;
	arena->size_list = elmt_src->size_list;
}

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

void	copy_processes(t_arena *arena)
{
	t_process       *src_process;
	t_process       *new_process;
	t_process       *prev_process;

	src_process = arena->next->process;
	while (src_process)
	{
		if (!(new_process = (t_process *)malloc(sizeof(t_process))))
			ft_exit();
		new_process->pc = arena->map + (src_process->pc - arena->next->map);
		copy_tab_process(new_process, src_process);
		new_process->alive = src_process->alive;
		new_process->valid_encodage = src_process->encodage;
		new_process->encodage = src_process->encodage;
		new_process->cycle_decount = src_process->cycle_decount;
		new_process->index = src_process->index;
		new_process->size_instruction = src_process->size_instruction;
		new_process->color = src_process->color;
		new_process->carry = src_process->carry;
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

void	copy_champions(t_arena *arena)
{
	t_champion      *src_champion;
	t_champion      *new_champion;
	t_champion      *prev_champion;

	src_champion = arena->next->champion;
	while (src_champion)
	{
		if (!(new_champion = (t_champion *)malloc(sizeof(t_champion))))
			ft_exit();
		new_champion->name = src_champion->name;
		new_champion->comment = src_champion->comment;
		new_champion->size_instructions = src_champion->size_instructions;
		new_champion->number = src_champion->number;
		new_champion->color = src_champion->color;
		new_champion->last_live = src_champion->last_live;
		new_champion->period_live_nb = src_champion->period_live_nb;
		new_champion->arena = arena;
		if (!arena->champion)
			arena->champion = new_champion;
		else
			prev_champion->next = new_champion;
		prev_champion = new_champion;
		src_champion = src_champion->next;
	}
	new_champion->next = NULL;
}

void	add_cycle_to_list(t_arena **arena)
{
	create_new_arena(arena);
	copy_map(*arena);
	copy_simple_data(*arena);
	copy_champions(*arena);
	copy_processes(*arena);
}
