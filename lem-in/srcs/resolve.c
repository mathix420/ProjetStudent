/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:29:24 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/24 14:23:56 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		clean_ant(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		if (tmp->nb_ant != 1 && !tmp->lock)
			tmp->nb_ant = 0;
		tmp = tmp->next;
	}
}

static int		malloc_tab(t_env *e)
{
	int		malloc_size;

	malloc_size = e->room->node->nb_next;
	if (!(e->tab_size = (int *)ft_memalloc(sizeof(int) * malloc_size)))
		return (0);
	if (!(e->tab_ant = (int *)ft_memalloc(sizeof(int) * malloc_size)))
		return (0);
	if (!(e->tab_id = (int *)ft_memalloc(sizeof(int) * malloc_size)))
		return (0);
	return (1);
}

static void		reseting_var(t_env *e)
{
	int		malloc_size1;
	int		malloc_size2;

	malloc_size1 = e->room->node->nb_next;
	malloc_size2 = malloc_size1 - e->count;
	e->steps = -1;
	e->lock_var = -1;
	ft_bzero(e->tab_ant, sizeof(int) * malloc_size1);
}

static int		last_call_results(t_env *e)
{
	int		i;
	t_node	*start;
	t_node	*node_tmp;

	i = -1;
	start = e->room->node;
	node_tmp = NULL;
	while (++i < start->nb_next)
	{
		if (start->next[i]->room->nb_ant == 1
			&& start->next[i]->room->id != e->info.end_id
			&& (start->next[i] != node_tmp || !node_tmp))
		{
			node_tmp = start;
			start = start->next[i]->room->node;
			i = -1;
		}
	}
	clean_ant(e);
	if (start->room->id == e->info.start_id)
		return (0);
	else
		start->room->nb_ant = 0;
	return (1);
}

static int		clean_count(t_env *e)
{
	t_room	*tmp;
	int		max_id;

	tmp = e->room;
	max_id = 0;
	while (tmp)
	{
		tmp->lock = 0;
		if (tmp->nb_ant > max_id)
			max_id = tmp->nb_ant;
		tmp = tmp->next;
	}
	return (max_id);
}

static int		get_id(t_env *e, int nb_ant)
{
	int		i;

	i = -1;
	while (++i < e->room->node->nb_next)
		if (e->tab_id[i] == nb_ant)
			return (i);
	return (-1);
}

static void		print_one_round(t_env *e, t_node *start, int *passed)
{
	int		i;
	t_room	*room;
	int		id;

	clean_depth(e);
	enqueue(e, start);
	start->room->depth = 1;
	while (e->queue)
	{
		i = -1;
		while (++i < e->queue->node->nb_next)
		{
			if ((!e->queue->node->next[i]->room->depth  //si ya pas de depth
				&& e->queue->node->next[i]->room->nb_ant) // et qu'il est utilise 
				|| e->queue->node->next[i]->room->id == e->info.end_id) //ou si c'est la fin
			{
				room = e->queue->node->next[i]->room;
				room->depth = e->queue->node->room->depth + 1;
//				printf(" test %.2s from %s :: ", room->name, e->queue->node->room->name);
				if ((id = get_id(e, room->nb_ant)) >= 0 && room->depth == 2 && e->tab_ant[id]) // si c'est la premiere colone
				{
					if (!room->lock) //jamais assigne
						room->lock = *passed;
					else //over write
					{
						room->old_ant = room->lock;
						room->lock = *passed;
					}
					printf("L%d-%.2s ", *passed, room->name); //print
					*passed += 1;
					e->tab_ant[id]--;
				}
				else if (id >= 0 && room->depth == 2)
				{
					room->old_ant = room->lock;
					room->lock = 0;
				}
				else if (e->queue->node->room->old_ant)
				{
					room->old_ant = room->lock;
					room->lock = e->queue->node->room->old_ant;
					printf("L%d-%.2s ", room->lock, room->name); //print
					if (room->id == e->info.end_id)
					{
						e->info.nb_ant--;
						e->queue->node->room->old_ant = 0;
					}
				}
				if (room->id != e->info.end_id) // si c'est pas la fin
					enqueue(e, e->queue->node->next[i]);
			}
		}
//		print_tab(e);
		dequeue(e);
	}
}

static void		print_solution(t_env *e)
{
	int		nb_paths;
	int		passed;

	passed = 1;
	nb_paths = clean_count(e);
	clear_queue(e);
	while (e->info.nb_ant > 1)
	{
		print_one_round(e, e->room->node, &passed);
		printf("\n");
		clear_queue(e);
	}
}

static void		get_solution(t_env *e, int best_count)
{
	print_tab(e);
	e->count = 0;
	while (1)
	{
		reseting_var(e);
		bfs(e, e->room->node, e->solve_id);
		printf("%d == %d\n", e->count, best_count);
		if (e->count == best_count)
			return (print_solution(e));
		e->count++;
		e->solve_id++;
	}
	print_solution(e);
}

void			init_resolution(t_env *e)
{
	(!malloc_tab(e)) ? free_env(e, 2) : 0;
	while (1)
	{
		reseting_var(e);
		bfs(e, e->room->node, e->solve_id);
		print_call(e, e->best_call, 0, 0);
		if (e->lock_var != -1 || !e->count)
		{
			e->count++;
			e->solve_id++;
		}
		if (e->steps != -1 && (e->best_steps == -2 || e->best_steps > e->steps))
		{
			if (e->best_steps == -2 && e->steps == -1)
				break ;
			e->best_steps = e->steps;
			e->best_call = e->count;
		}
		if (!last_call_results(e))
			break ;
	}
	clean_ant(e);
	get_solution(e, e->best_call);
	printf("BEST CALL IS CALL %d FOR %d STEPS\n", e->best_call, e->best_steps);
}
