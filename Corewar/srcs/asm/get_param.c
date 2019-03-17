/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:41:39 by agissing          #+#    #+#             */
/*   Updated: 2019/03/17 18:47:47 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int		is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR
			|| c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

int						get_param(t_env *e, int index)
{
	int		ok;
	int		n;

	ok = -1;
	n = 0;
	while ((e->line[++e->x] || ok >= 0) && e->line[e->x] != COMMENT_CHAR)
	{
		if (ok == -1 && check_params(e, g_op_tab[index].encodage[n], n))
			ok = e->x;
		else if (ok >= 0 && is_end_param(e->line[e->x]) && (ok = -1))
		{
			n++;
			if (!e->line[e->x] && g_op_tab[index].nb_param == n)
				return (1);
			(!e->line[e->x]) ? p_error(e, BAD_PARAM_NUMBER) : 0;
		}
		else if (ok == -1 && !is_end_param(e->line[e->x]))
			p_error(e, UNKNOWN_COMMAND);
		if (e->line[e->x] == COMMENT_CHAR && g_op_tab[index].nb_param == n)
			return (1);
		else if (e->line[e->x] == COMMENT_CHAR || n > g_op_tab[index].nb_param)
			p_error(e, BAD_PARAM_NUMBER);
	}
	(g_op_tab[index].nb_param != n) ? p_error(e, BAD_PARAM_NUMBER) : 0;
	return (1);
}
