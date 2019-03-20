/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:01:05 by agissing          #+#    #+#             */
/*   Updated: 2019/03/20 14:52:33 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int		is_nbr_char(char c)
{
	return (c == '-' || c == '+' || (c >= '0' && c <= '9'));
}

static inline int		is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR
			|| c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

void					check_dir_ind(t_env *e, int direct)
{
	int		tmp;
	int		label;
	int		prfx;

	tmp = e->x;
	prfx = 0;
	e->x += !!direct;
	label = (e->line[e->x] == LABEL_CHAR);
	e->x += label;
	if (!label && (e->line[e->x] == '-' || e->line[e->x] == '+') && (prfx = 1))
		e->x++;
	while (!is_end_param(e->line[e->x]))
	{
		if ((label && !is_in_str(e->line[e->x], LABEL_CHARS))
			|| (!label && (e->line[e->x] < '0' || e->line[e->x] > '9')))
			p_error(e, BAD_PARAMETER);
		e->x++;
	}
	if (label && e->x == label + !!direct)
		p_error(e, BAD_LABEL_NAME);
	else if (!label && e->x == !!direct + prfx + tmp)
		p_error(e, BAD_PARAMETER);
	e->x = tmp;
	!direct ? add_ind(e) : add_dir(e);
	e->x = tmp;
}

void					check_reg(t_env *e)
{
	int		out;
	int		tmp;

	tmp = e->x;
	out = 0;
	while (!is_end_param(e->line[++e->x]) && (!out || out < REG_NUMBER))
		if (e->line[e->x] < '0' || e->line[e->x] > '9')
			p_error(e, BAD_PARAMETER);
		else
			out = out * 10 + e->line[e->x] - '0';
	if (!is_end_param(e->line[e->x]) || e->x-- == 1)
		p_error(e, BAD_PARAMETER);
	if (out < 1 || out > REG_NUMBER)
		p_error(e, LIMIT_SIZE);
	e->x = tmp;
	add_reg(e);
	e->x = tmp;
}

int						check_params(t_env *e, uint8_t enc, int count)
{
	uint8_t		val;

	val = 0;
	if (e->line[e->x] != DIRECT_CHAR && e->line[e->x] != LABEL_CHAR
		&& e->line[e->x] != 'r' && !is_nbr_char(e->line[e->x]))
		return (0);
	if (e->line[e->x] == DIRECT_CHAR)
	{
		val |= T_DIR;
		(e->ocp) ? *e->ocp_char |= 2 << ((3 - count) * 2) : 0;
		check_dir_ind(e, 1);
	}
	else if (e->line[e->x] == LABEL_CHAR || is_nbr_char(e->line[e->x]))
	{
		val |= T_IND;
		(e->ocp) ? *e->ocp_char |= 3 << ((3 - count) * 2) : 0;
		check_dir_ind(e, 0);
	}
	else if (e->line[e->x] == 'r' && (val |= T_REG))
	{
		(e->ocp) ? *e->ocp_char |= 1 << ((3 - count) * 2) : 0;
		check_reg(e);
	}
	!(val & enc) ? p_error(e, BAD_PARAMETER) : 0;
	return (1);
}
