/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 19:25:02 by agissing          #+#    #+#             */
/*   Updated: 2019/01/09 18:56:41 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sorting(t_op *ops)
{
	if (ops)
		print_sorting(ops->next);
	if (ops && ops->nb == 1)
		ft_putstr("sa\n");
	else if (ops && ops->nb == 2)
		ft_putstr("sb\n");
	else if (ops && ops->nb == 3)
		ft_putstr("ss\n");
	else if (ops && ops->nb == 4)
		ft_putstr("ra\n");
	else if (ops && ops->nb == 5)
		ft_putstr("rb\n");
	else if (ops && ops->nb == 6)
		ft_putstr("rr\n");
	else if (ops && ops->nb == 7)
		ft_putstr("rra\n");
	else if (ops && ops->nb == 8)
		ft_putstr("rrb\n");
	else if (ops && ops->nb == 9)
		ft_putstr("rrr\n");
	else if (ops && ops->nb == 10)
		ft_putstr("pa\n");
	else if (ops && ops->nb == 11)
		ft_putstr("pb\n");
}

void	clean_sorting(t_op *o)
{
	t_op	*next;
	t_op	*last;

	last = NULL;
	while (o && o->next)
	{
		next = o->next;
		while (next->next && next->nb == 0)
			next = next->next;
		if ((o->nb == 4 && next->nb == 7) || (o->nb == 5 && next->nb == 8) ||
			(o->nb == 7 && next->nb == 4) || (o->nb == 8 && next->nb == 5))
		{
			o->nb = 0;
			next->nb = 0;
			last ? (o = last) :
				(last = o);
			if (!last)
				o = next->next;
		}
		else
		{
			last = o;
			o = next;
		}
	}
}
