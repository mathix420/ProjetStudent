/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:05:03 by agissing          #+#    #+#             */
/*   Updated: 2019/01/08 19:43:40 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int c, char **v)
{
	t_stack		*stck_a;
	t_stack		*stck_b;
	t_sort		vars;
	int			i;

	i = c - 1;
	stck_a = NULL;
	if (!(stck_b = NULL) && c < 3)
		return (0);
	while (i >= 1)
		if (!(stck_a = ft_new_elem(ft_atoi(v[i--]), stck_a)))
			return (0);
	vars.count = c - 1;
	vars.bc = 0;
	if (is_ok_a(stck_a, c) || !(vars.op = ft_memalloc(sizeof(t_op))))
		return (0);
	sort_a(&stck_a, &stck_b, vars);
	clean_sorting(*vars.op);
	clean_sorting(*vars.op);
	clean_sorting(*vars.op);
	print_sorting(*vars.op);
	ft_free_ops(*vars.op);
	free(vars.op);
	ft_free_list(stck_a);
	ft_free_list(stck_b);
}
