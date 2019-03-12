/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:25 by agissing          #+#    #+#             */
/*   Updated: 2019/03/12 17:35:00 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						add_op(t_env *e, int index)
{
	e->op_char = &e->data.champ[e->i];
	add_to_champ(e, g_op_tab[index].op_code);
	if ((e->ocp = g_op_tab[index].ocp))
		e->ocp_char = &e->data.champ[add_i(e)];
	else
		e->ocp_char = NULL;
	e->index = index;
	return (get_param(e, index));
}

void					add_ind(t_env *e)
{
	short	value;

	value = get_value(e, 2);
	add_to_champ(e, (value & 0xff00) >> 8);
	add_to_champ(e, value & 0xff);
}

void					add_dir(t_env *e)
{
	int		value;

	if (g_op_tab[e->index].direct_size)
	{
		value = (short)get_value(e, 2);
		add_to_champ(e, (value & 0xff00) >> 8);
		add_to_champ(e, value & 0xff);
	}
	else
	{
		value = get_value(e, 4);
		add_to_champ(e, (value & 0xff000000) >> 24);
		add_to_champ(e, (value & 0xff0000) >> 16);
		add_to_champ(e, (value & 0xff00) >> 8);
		add_to_champ(e, value & 0xff);
	}
}

void					add_reg(t_env *e)
{
	add_to_champ(e, get_value(e, 1));
}
