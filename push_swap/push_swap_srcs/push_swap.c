/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:05:03 by agissing          #+#    #+#             */
/*   Updated: 2019/01/04 19:46:06 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_moy(t_stack *pile, int max)
{
	long long	somme;
	int			count;

	count = 1;
	somme = pile->nb;
	while (pile->before && count <= max)
	{
		pile = pile->before;
		somme += pile->nb;
		count++;
	}
	return (somme / count);
}

void	rra_or_ra(int re, t_stack **pila, int l)
{
	re %= l;
	if (l - re < re)
		while (re++ < l)
		{
			*pila = rotate(*pila);
			ft_putstr("ra\n");
		}
	else
		while (re--)
		{
			*pila = reverse(*pila);
			ft_putstr("rra\n");
		}
}

int		is_ok_a(t_stack *pile, int max)
{
	while (pile->before && max--)
	{
		if (pile->nb > pile->before->nb)
			return (0);
		pile = pile->before;
	}
	return (1);
}

int		is_ok_b(t_stack *pile, int max)
{
	while (pile->before && max--)
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
	if (!is_ok_a(*pila, -1))
	{
		*pila = rotate(*pila);
		if (swap_if(*pila))
			ft_putstr("ra\nsa\nrra\n");
		*pila = reverse(*pila);
		swap_if(*pila) ? ft_putstr("sa\n") : 0;
	}
}

void	sort_a(t_stack **pila, t_stack **pilb, int count, int bc)
{
	int		moy;
	int		re;
	int		pe;
	int		c;

	c = count;
	if (c == 3)
		small_sort_a(pila);
	else if (c == 2 && !is_ok_a(*pila, c))
	{
		if (bc == 2 && !is_ok_b(*pilb, 2))
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
	if (c <= 1 || is_ok_a(*pila, c))
		return ;
	moy = ft_moy(*pila, c);
	re = 0;
	pe = 0;
	while (c > 1)
	{
		if ((*pila)->nb >= moy) //Simplification ici =======================================
		{
			*pila = rotate(*pila);
			ft_putstr("ra\n");
			re ++;
		}
		else
		{
			push(pila, pilb);
			ft_putstr("pb\n");
			pe++;
		}	
		c--;
	}
	re %= count - pe;

	rra_or_ra(re, pila, count - pe);
	sort_a(pila, pilb, count - pe, pe);
//	sort_b(pila, pilb, pe);
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

	if (is_ok_a(stck_a, c))
		ft_putstr("============ Deja OK ==============\n");
	sort_a(&stck_a, &stck_b, c - 1, 0);

	ft_putstr("A : ");
	print_stack(stck_a);	
	ft_putstr("B : ");
	print_stack(stck_b);
}
