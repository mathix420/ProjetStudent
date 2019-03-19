/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 15:41:39 by agissing          #+#    #+#             */
/*   Updated: 2019/03/18 17:59:27 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int		is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR);
}

static inline int		is_spc(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

static inline void		go_to_end(t_env *e, int n)
{
	n = 0;
	while (!is_end_param(e->line[e->x]) && !is_spc(e->line[e->x]))
		e->x++;
}

int						get_param(t_env *e, int id)
{
	int		n;

	n = 0;
	while (e->line[e->x] && e->line[e->x] != COMMENT_CHAR)
	{
		while (is_spc(e->line[e->x]))
			e->x++;
		if (e->line[e->x] == COMMENT_CHAR)
			break ;
		if (!check_params(e, g_op_tab[id].encodage[n], n))
			p_error(e, UNKNOWN_COMMAND);
		else if (n < g_op_tab[id].nb_param)
			go_to_end(e, n++);
		else
			p_error(e, BAD_PARAM_NUMBER);
		while (is_spc(e->line[e->x]))
			e->x++;
		if (!is_end_param(e->line[e->x]))
			p_error(e, BAD_SYNTAXE);
		else if (e->line[e->x] == SEPARATOR_CHAR && e->line[e->x + 1])
			e->x++;
	}
	return (1);
}
