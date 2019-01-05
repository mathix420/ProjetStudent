/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:05:03 by agissing          #+#    #+#             */
/*   Updated: 2019/01/05 20:09:25 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_moy(t_stack *pile, int max)
{
	long long	somme;
	int			count;

	count = 1;
	somme = pile->nb;
	while (pile->before && count < max)
	{
		pile = pile->before;
		somme += pile->nb;
		count++;
	}
	return (somme / count);
}

void	ft_add_op(t_op **op, int nb)
{
	t_op	*new;

	if (!*op)
	{
		if (!(*op = ft_memalloc(sizeof(t_op))))
			return ;
		(*op)->nb = nb;
		(*op)->next = NULL;
	}
	else
	{
		if (!(new = ft_memalloc(sizeof(t_op))))
			return ;
		new->nb = nb;
		new->next = *op;
		*op = new;
	}
}

void	ft_remlast(t_op **op)
{
	t_op	*tmp;

	if (!*op)
		return ;
	tmp = (*op)->next;
	free(*op);
	*op = tmp;
}

int		ft_len(t_stack *pile)
{
	int		i;

	i = 0;
	while (pile)
	{
		i++;
		pile = pile->before;
	}
	return (i);
}

void	rra_or_ra(int re, t_stack **pila, int l, t_sort v)
{
	if (l <= 0)
		return ;
	re %= l;
	if (l - re < re)
		while (re++ < l)
		{
			*pila = rotate(*pila);
			ft_add_op(v.op, 4);
		}
	else
		while (re--)
		{
			*pila = reverse(*pila);
			ft_add_op(v.op, 7);
		}
}

void	rrb_or_rb(int re, t_stack **pilb, int l, t_sort v)
{
	if (l <= 0)
		return ;
	re %= l;
	if (l - re < re)
		while (re++ < l)
		{
			*pilb = rotate(*pilb);
			ft_add_op(v.op, 5);
		}
	else
		while (re--)
		{
			*pilb = reverse(*pilb);
			ft_add_op(v.op, 8);
		}
}

int		is_ok_a(t_stack *pile, int max)
{
	while (pile->before && --max)
	{
		if (pile->nb > pile->before->nb)
			return (0);
		pile = pile->before;
	}
	return (1);
}

int		is_ok_b(t_stack *pile, int max)
{
	while (pile->before && --max)
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

void	small_sort_a(t_stack **pila, t_sort v)
{
	int		re;

	re = 0;
	swap_if(*pila) ? ft_add_op(v.op, 1) : 0;
	if (!is_ok_a(*pila, -1))
	{
		*pila = rotate(*pila);
		if (swap_if(*pila))
		{
			ft_add_op(v.op, 4);
			ft_add_op(v.op, 1);
			ft_add_op(v.op, 7);
		}
		*pila = reverse(*pila);
		swap_if(*pila) ? ft_add_op(v.op, 1) : 0;
	}
}

int		swap_if_b(t_stack *pile)
{
	if (pile->nb < pile->before->nb)
	{
		swap(pile);
		return (1);
	}
	return (0);
}

void	small_sort_b(t_stack **pila, t_stack **pilb, t_sort v)
{
	swap_if_b(*pilb) ? ft_add_op(v.op, 2) : 0;
	push(pilb, pila);
	ft_add_op(v.op, 10);
	swap_if_b(*pilb) ? ft_add_op(v.op, 2) : 0;
	push(pilb, pila);
	ft_add_op(v.op, 10);
	swap_if(*pila) ? ft_add_op(v.op, 1) : 0;
	push(pilb, pila);
	ft_add_op(v.op, 10);
}

void	sort_b(t_stack **pila, t_stack **pilb, t_sort v)
{
	int		moy;
	int		re;
	int		pe;
	int		c;

	c = v.bc;
	if (c == 3)
	{
		small_sort_b(pila, pilb, v);
		return ;
	}
	else if (c == 2 && !is_ok_b(*pilb, 2))
	{
		swap(*pilb);
		ft_add_op(v.op, 2);
	}
	if (c <= 1 || is_ok_b(*pilb, c))
	{
		while (c--)
		{
			push(pilb, pila);
			ft_add_op(v.op, 10);
		}
		return ;
	}
	moy = ft_moy(*pilb, c);
	re = 0;
	pe = 0;
	while (c > 0)
	{
		if ((*pilb)->nb < moy) //Simplification ici =======================================
		{
			*pilb = rotate(*pilb);
			ft_add_op(v.op, 5);
			re ++;
		}
		else
		{
			push(pilb, pila);
			ft_add_op(v.op, 10);
			pe++;
		}
		c--;
	}
	rrb_or_rb(re, pilb, ft_len(*pilb), v);
	v.bc -= pe;
	v.count = pe;
	sort_a(pila, pilb, v);
	sort_b(pila, pilb, v);
}

void	sort_a(t_stack **pila, t_stack **pilb, t_sort v)
{
	int		moy;
	int		re;
	int		pe;
	int		c;

	c = v.count;
	if (c == 3)
	{
		small_sort_a(pila, v);
		return ;
	}
	else if (c == 2 && !is_ok_a(*pila, c))
	{
		if (v.bc == 2 && !is_ok_b(*pilb, 2))
		{
			ss(*pila, *pilb);
			ft_add_op(v.op, 3);
		}
		else
		{
			swap(*pila);
			ft_add_op(v.op, 1);
		}
		return ;
	}
	if (c <= 1 || is_ok_a(*pila, c))
		return ;
	moy = ft_moy(*pila, c);
	re = 0;
	pe = 0;
	while (c > 0)
	{
		if ((*pila)->nb > moy) //Simplification ici =======================================
		{
			*pila = rotate(*pila);
			ft_add_op(v.op, 4);
			re ++;
		}
		else
		{
			push(pila, pilb);
			ft_add_op(v.op, 11);
			pe++;
		}
		c--;
	}
	rra_or_ra(re, pila, ft_len(*pila), v);
	v.count -= pe;
	v.bc = pe;
	sort_a(pila, pilb, v);
	sort_b(pila, pilb, v);
}

void	print_sorting(t_op *ops)
{
	if (!ops)
		return ;
	print_sorting(ops->next);
	if (ops->nb == 1)
		ft_putstr("sa\n");
	else if (ops->nb == 2)
		ft_putstr("sb\n");
	else if (ops->nb == 3)
		ft_putstr("ss\n");
	else if (ops->nb == 4)
		ft_putstr("ra\n");
	else if (ops->nb == 5)
		ft_putstr("rb\n");
	else if (ops->nb == 6)
		ft_putstr("rr\n");
	else if (ops->nb == 7)
		ft_putstr("rra\n");
	else if (ops->nb == 8)
		ft_putstr("rrb\n");
	else if (ops->nb == 9)
		ft_putstr("rrr\n");
	else if (ops->nb == 10)
		ft_putstr("pa\n");
	else if (ops->nb == 11)
		ft_putstr("pb\n");
}

int		main(int c, char **v)
{
	t_stack		*stck_a;
	t_stack		*stck_b;
	t_sort		vars;
	int			i;

	i = 1;
	stck_a = NULL;
	stck_b = NULL;
	if (c < 3)
		return (0);
	while (i < c)
		stck_a = ft_new_elem(ft_atoi(v[i++]), stck_a);

/*	ft_putstr("A : ");
	print_stack(stck_a);
	ft_putstr("B : ");
	print_stack(stck_b);*/

	if (is_ok_a(stck_a, c))
		ft_putstr("============ Deja OK ==============\n");
	vars.count = c - 1;
	vars.bc = 0;
	if (!(vars.op = ft_memalloc(sizeof(t_op))))
		return (0);
	sort_a(&stck_a, &stck_b, vars);

	print_sorting(*vars.op);
	
/*	ft_putstr("A : ");
	print_stack(stck_a);	
	ft_putstr("B : ");
	print_stack(stck_b);*/
}
