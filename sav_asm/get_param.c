/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:41:39 by agissing          #+#    #+#             */
/*   Updated: 2019/03/11 15:56:58 by agissing         ###   ########.fr       */
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
	int		n_par;

	ok = -1;
	n_par = 0;
	while ((e->line[++e->x] || ok >= 0) && e->line[e->x] != COMMENT_CHAR)
	{
		if (ok == -1 && check_params(e, g_op_tab[index].encodage[n_par], n_par))
			ok = e->x;
		else if (ok >= 0 && is_end_param(e->line[e->x]))
		{
			ok = -1;
			n_par++;
			if (!e->line[e->x] && g_op_tab[index].nb_param == n_par)
				return (1);
			(!e->line[e->x]) ? p_error(e, BAD_PARAM_NUMBER) : 0;
		}
		else if (ok == -1 && !is_end_param(e->line[e->x]))
			p_error(e, UNKNOWN_COMMAND);
		if (e->line[e->x] == COMMENT_CHAR && g_op_tab[index].nb_param == n_par)
			return (1);
		else if (e->line[e->x] == COMMENT_CHAR || n_par > g_op_tab[index].nb_param)
			p_error(e, BAD_PARAM_NUMBER);
	}
	if (g_op_tab[index].nb_param != n_par)
		p_error(e, BAD_PARAM_NUMBER);
	return (1);
}
