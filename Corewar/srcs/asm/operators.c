/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:25 by agissing          #+#    #+#             */
/*   Updated: 2019/03/08 21:50:28 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int		is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR
			|| c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

int						add_op(t_env *e, int index)
{
	e->op_char = &e->data.champ[e->i];
	e->data.champ[e->i++] = g_op_tab[index].op_code;
	if ((e->ocp = g_op_tab[index].ocp))
		e->ocp_char = &e->data.champ[e->i++];
	else
		e->ocp_char = NULL;
	e->index = index;
	return (get_param(e, index));
}

int						get_value(t_env *e, int nb_oct)
{
	uint64_t	out;
	char		*str;
	int			sign;

	out = 0;
	sign = 1;
	str = e->line;
	while (str[e->x] == LABEL_CHAR || str[e->x] == DIRECT_CHAR
												|| str[e->x] == 'r')
		if (str[e->x++] == LABEL_CHAR)
			return (label_to_put(e, nb_oct));
	if (str[e->x] == '-' || str[e->x] == '+')
		sign = (str[e->x++] == '-' ? -1 : 1);
	while (str[e->x] >= '0' && str[e->x] <= '9' && !is_end_param(str[e->x]))
	{
		out = (out * 10) + (str[e->x++] - '0');
		if (out > 4294967295)
			p_error(e, BAD_PARAM_NUMBER);
	}
	return ((uint32_t)out * (uint32_t)sign);
}

void					add_ind(t_env *e)
{
	short	value;

	value = get_value(e, 2);
	e->data.champ[e->i++] = (value & 0xff00) >> 8;
	e->data.champ[e->i++] = value & 0xff;
}

void					add_dir(t_env *e)
{
	int		value;

	if (g_op_tab[e->index].direct_size)
	{
		value = (short)get_value(e, 2);
		e->data.champ[e->i++] = (value & 0xff00) >> 8;
		e->data.champ[e->i++] = value & 0xff;
	}
	else
	{
		value = get_value(e, 4);
		e->data.champ[e->i++] = (value & 0xff000000) >> 24;
		e->data.champ[e->i++] = (value & 0xff0000) >> 16;
		e->data.champ[e->i++] = (value & 0xff00) >> 8;
		e->data.champ[e->i++] = value & 0xff;
	}
}

void					add_reg(t_env *e)
{
	e->data.champ[e->i++] = (uint8_t)get_value(e, 1);
}
