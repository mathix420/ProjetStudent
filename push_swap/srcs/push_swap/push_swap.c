/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:05:03 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 22:36:30 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_all(t_sort vars)
{
	clean_sorting(*vars.op);
	clean_sorting(*vars.op);
	clean_sorting(*vars.op);
	print_sorting(*vars.op);
	ft_free_ops(*vars.op);
	free(vars.op);
}

int		ft_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int		main(int c, char **v)
{
	t_stack		*pila;
	t_stack		*pilb;
	t_sort		vars;

	pila = NULL;
	pilb = NULL;
	if (c < 2)
		return (0);
	vars.count = c - 1;
	vars.bc = 0;
	if (!ft_options(c, v, &pila, &vars) || is_ok_a(pila, vars.count) ||
		!(vars.op = ft_memalloc(sizeof(t_op))))
		return (0);
	rev_check(&pila, &pilb, vars);
	print_all(vars);
	ft_free_list(pila);
	ft_free_list(pilb);
}
