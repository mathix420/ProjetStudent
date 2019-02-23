/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:29:24 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/23 13:45:56 by acompagn         ###   ########.fr       */
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
//	ft_bzero(e->tab_size + e->count, sizeof(int) * malloc_size2);
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

void			init_resolution(t_env *e)
{
	int		best_steps;
	int		best_call;
	int		solve_id;

	best_steps = -2;
	best_call = 0;
	e->count = 0;
	solve_id = 0;
	int		bla = 0;
	if (!(malloc_tab(e)))
		printf("do some free\n");
	while (1)
	{
		reseting_var(e);
		bfs(e, e->room->node, solve_id);
		print_call(e, best_call, 0, 0);
		if (e->lock_var != -1 || !e->count)
		{
			e->count++;
			solve_id++;
		}
		bla++;
		if (e->steps != -1 && (best_steps == -2 || best_steps > e->steps))
		{
			best_steps = e->steps;
			best_call = e->count;
		}
		if (!last_call_results(e))
		{
			printf("======= BEST CALL = %d ===========\n", best_call);
			break ;
		}
	}
}
