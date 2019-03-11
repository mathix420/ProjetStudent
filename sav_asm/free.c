/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 14:49:19 by agissing          #+#    #+#             */
/*   Updated: 2019/03/10 14:53:54 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_struct(t_env *e)
{
	t_label		*tmp;
	t_todo		*to_free;

	while (e->labels)
	{
		tmp = e->labels;
		e->labels = e->labels->next;
		free(tmp->name);
		free(tmp);
	}
	while (e->to_put)
	{
		to_free = e->to_put;
		e->to_put = e->to_put->next;
		free(to_free->name);
		free(to_free);
	}
}
