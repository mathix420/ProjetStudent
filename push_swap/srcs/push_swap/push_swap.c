/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:05:03 by agissing          #+#    #+#             */
/*   Updated: 2019/01/14 18:34:07 by agissing         ###   ########.fr       */
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

int		ft_free_error(t_stack *pila)
{
	ft_free_list(pila);
	return (ft_error());
}

int		main(int c, char **v)
{
	t_stack		*pila;
	t_stack		*pilb;
	t_sort		vars;

	pila = NULL;
	pilb = NULL;
	if (c < 2 || !ft_options(c, v, &pila, &vars) || !duplicates_check(pila))
		return (ft_free_error(pila));
	vars.bc = 0;
	if (is_ok_a(pila, vars.count) || !(vars.op = ft_memalloc(sizeof(t_op))))
	{
		ft_free_list(pila);
		return (0);
	}
	rev_check(&pila, &pilb, vars);
	print_all(vars);
	ft_free_list(pila);
	ft_free_list(pilb);
}
