/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:18:19 by agissing          #+#    #+#             */
/*   Updated: 2019/01/13 18:45:16 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		duplicates_check(t_stack *pile)
{
	t_stack	*sav;
	t_stack	*p1;

	while (pile)
	{
		p1 = pile;
		sav = p1 ? p1->before : p1;
		while (sav)
			if (!p1 || p1->nb != sav->nb)
				sav = sav->before;
			else
				return (0);
		pile = p1 ? p1->before : p1;
	}
	return (!p1 || !pile || p1->nb != pile->nb);
}
