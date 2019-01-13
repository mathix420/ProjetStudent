/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:18:19 by agissing          #+#    #+#             */
/*   Updated: 2019/01/13 17:41:38 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		duplicates_check(t_stack *pile)
{
	t_stack	*sav;
	t_stack	*p1;
	t_stack	*p2;
	t_stack	*p3;
	t_stack	*p4;

	while (pile)
	{
		p1 = pile->before;
		p2 = p1 ? p1->before : NULL;
		p3 = p2 ? p2->before : NULL;
		p4 = p3 ? p3->before : NULL;
		sav = p4 ? p4->before : p4;
		while (sav)
		{
			if ((!p1 || p1->nb != sav->nb) &&
				(!p2 || p2->nb != p1->nb != sav->nb) &&
				(!p3 || p1->nb != p2->nb != p3->nb != sav->nb) &&
				(!p4 || p4->nb != p1->nb != p2->nb != p3->nb != sav->nb))
				sav = sav->before;
			else
				return (0);
		}
		pile = p4 ? p4->before : NULL;
	}
	return ((!p2 || p1->nb != p2->nb) &&
			(!p3 || p1->nb != p2->nb != p3->nb) &&
			(!p4 || p1->nb != p2->nb != p3->nb != p4->nb));
}
