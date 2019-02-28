/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:50:53 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/28 18:31:44 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		malloc_tab(t_env *e)
{
	int		malloc_size;

	malloc_size = e->room->node->nb_next;
	if (!(e->tab_size = (int *)ft_memalloc(sizeof(int) * (malloc_size + 10))))
	{
		free_env(e, 2);
		return (0);
	}
	if (!(e->tab_ant = (int *)ft_memalloc(sizeof(int) * (malloc_size + 10))))
	{
		free_env(e, 2);
		return (0);
	}
	if (!(e->tab_id = (int *)ft_memalloc(sizeof(int) * (malloc_size + 10))))
	{
		free_env(e, 2);
		return (0);
	}
	return (1);
}

static void		reseting_var(t_env *e)
{
	e->lock_var = -1;
	if (e->steps != -1)
		clean_unused_path(e);
	ft_bzero(e->tab_ant, sizeof(int) * (e->room->node->nb_next + 10));
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

void			init_solve(t_env *e, int break_solve)
{
	(!break_solve) ? malloc_tab(e) : 1;
	while (1)
	{
		reseting_var(e);
		bfs(e, e->room->node, e->solve_id);
		if (e->lock_var != -1 || !e->count)
		{
			e->count++;
			e->solve_id++;
		}
		if (e->steps != -1 && (e->best_steps == -2 || e->best_steps > e->steps))
		{
			if (e->best_steps == -2 && e->steps == -1)
				break ;
			if (!break_solve)
			{
				e->best_steps = e->steps;
				e->best_call = e->count;
			}
		}
		if (break_solve && e->best_call == e->count)
			break ;
		if (!last_call_results(e))
			break ;
	}
}
