/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:05:03 by agissing          #+#    #+#             */
/*   Updated: 2019/01/04 17:53:47 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ok_a(t_stack *pile)
{
	while (pile->before)
	{
		if (pile->nb > pile->before->nb)
			return (0);
		pile = pile->before;
	}
	return (1);
}

int		is_ok_b(t_stack *pile)
{
	while (pile->before)
	{
		if (pile->nb < pile->before->nb)
			return (0);
		pile = pile->before;
	}
	return (1);
}

int		swap_if(t_stack *pila)
{
	if (pila->nb > pila->before->nb)
	{
		swap(pila);
		return (1);
	}
	return (0);
}

void	small_sort_a(t_stack **pila)
{
	int		re;

	re = 0;
	swap_if(*pila) ? ft_putstr("sa\n") : 0;
	if (!is_ok_a(*pila))
	{
		*pila = rotate(*pila);
		if (swap_if(*pila))
			ft_putstr("ra\nsa\nrra\n");
		*pila = reverse(*pila);
		swap_if(*pila) ? ft_putstr("sa\n") : 0;
	}
}

void	sort_a(t_stack **pila, t_stack **pilb, int c, int bc)
{
	if (c == 3)
		small_sort_a(pila);
	else if (c == 2 && !is_ok_a(*pila))
	{
		if (bc == 2 && !is_ok_b(*pilb))
		{
			ss(*pila, *pilb);
			ft_putstr("ss\n");
		}
		else
		{
			swap(*pila);
			ft_putstr("sa\n");
		}
	}
	if (c <= 1 || is_ok_a(*pila))
		return ;
}

int		main(int c, char **v)
{
	t_stack		*stck_a;
	t_stack		*stck_b;
	int			i;

	t_stack     *tmp;
    t_stack     *tmp2;

	i = 1;
	stck_a = NULL;
	stck_b = NULL;
	if (c < 3)
		return (0);
	while (i < c)
		stck_a = ft_new_elem(ft_atoi(v[i++]), stck_a);

	ft_putstr("A : ");
	print_stack(stck_a);
	ft_putstr("B : ");
	print_stack(stck_b);

	if (is_ok_a(stck_a))
		ft_putstr("============ Deja OK ==============\n");
	sort_a(&stck_a, &stck_b, c - 1, 0);

	ft_putstr("A : ");
	print_stack(stck_a);	
	ft_putstr("B : ");
	print_stack(stck_b);
}
