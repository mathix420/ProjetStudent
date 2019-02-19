/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 10:29:24 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/19 22:50:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				shortest(t_env *e, t_room *end_ptr)
{
	int		i;
	t_node	*node_min;
	t_node	*node;
	t_node	**node_ptr;

	i = -1;
	node_min = NULL;
	node = end_ptr->node;
	node_ptr = end_ptr->node->next;
	while (++i < node->nb_next)
		if (!node_min || node_ptr[i]->room->depth < node_min->room->depth)
			node_min = node_ptr[i];
	if (node_min->room->depth >= e->info.nb_ant)
		printf("shortest path solution\n");
	else
		printf("try another\n");
}

static inline int	abss(int nb)
{
	return (nb >= 0 ? nb : -nb);
}

static inline int	greater(int nb1, int nb2)
{
	printf("%d ===== %d\n", nb1, nb2);
	return (nb1 > nb2 ? nb1 : nb2);
}

void				print_tab3(t_env *e)
{
	int		i;

	i = -1;
	while (++i <= e->end_ptr->node->nb_next)
		printf("%d  ", e->tab_size[i]);
	printf("\n");
}

//int       dd = 0;

int					do_smth(t_env *e, int path_size)
{
	int		ant_1;
	int		ant_2;
	int		step1;
	int		step2;
	int		gap;

	step1 = e->steps - 1;
	step2 = path_size;
	ant_1 = e->info.nb_ant - 1;
	ant_2 = 1;
	gap = 0;
	if (e->steps == -1)
	{
		e->room->nb_ant = 0;
		e->steps = path_size + e->info.nb_ant - 1;
//		printf("first e->steps = %d\n", e->steps);
		step1 = e->id_way++;
		if ((gap = solve(e, e->end_ptr->node, 0)) || (e->id_way-- && 0))
			e->tab_size[step1 - 1] = path_size;
		return (gap);
	}
	while ((step1 > step2 || gap > abss(step1 - step2)) && ant_1 > 0)
	{
		gap = abss(step1 - step2);
		ant_1--;
		ant_2++;
		step1--;
		step2++;
	}
	if (gap < abss(step1 - step2))
	{
		ant_1++;
		ant_2--;
		step1++;
		step2--;
	}
//	printf("%d %d\n", e->steps, (step1 = greater(step1, step2)));
	if (e->steps >=	(step1 = greater(step1, step2)))
	{
		e->room->nb_ant = 0;
		e->steps = step1;
		step1 = e->id_way++;
		solve(e, e->end_ptr->node, 0);
		e->tab_size[step1 - 1] = path_size;
		return (1);
	}
	return (0);
}

int					solve(t_env *e, t_node *node, int steps)
{
	t_node	**tmp;
	int		i;

	if (node->room->id == e->info.start_id)
		return (do_smth(e, steps));
	i = -1;
	tmp = node->next;
	while (++i < node->nb_next)
		if (!tmp[i]->room->nb_ant)
		{
			printf("POSE :: %s\n", tmp[i]->room->name);
			tmp[i]->room->nb_ant = e->id_way;
			if (solve(e, tmp[i], steps + 1))
				return (1);
			printf("ENLEVE :: %s\n", tmp[i]->room->name);
			tmp[i]->room->nb_ant = 0;
		}
	return (0);
}


void				print_room(t_env *e)
{
	t_room	*tmp;

	tmp = e->room;
	while (tmp)
	{
		printf("%s ==== %d\n", tmp->name, tmp->nb_ant);
		tmp = tmp->next;
	}
}

int					init_solve(t_env *e)
{
	if (!(e->tab_size = (int *)ft_memalloc(sizeof(int) * e->end_ptr->node->nb_next)))
		return (0);
	if (!solve(e, e->end_ptr->node, 0))
		printf("DONE\n");
	print_tab3(e);
	return (1);
}

void				resolution(t_env *e)
{
	init_solve(e);
//	distribute(e);
}


void				init_resolution(t_env *e)
{
	t_room	*end_ptr;

	end_ptr = e->room;
	while (end_ptr->next)
		end_ptr = end_ptr->next;
	e->end_ptr = end_ptr;
	e->end_ptr->nb_ant = 1;

/*	int		i;

	i = -1;
	while (++i < e->end_ptr->node->nb_next)
	{
		printf("dd :: %s == %d\n", e->end_ptr->node->next[i]->room->name, e->end_ptr->node->next[i]->room->depth);
	}
*/
	bfs(e, e->end_ptr->node);
	print_room(e);
//	resolution(e);
}
