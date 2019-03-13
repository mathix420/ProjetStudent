/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:34:30 by agissing          #+#    #+#             */
/*   Updated: 2019/03/13 16:51:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int				is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR
			|| c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

void							put_blank(t_env *e)
{
	int		i;
	int		j;

	i = e->x;
	j = 0;
	while (i >= 0 && !is_end_param(e->line[i]))
		i--;
	while (i >= 0)
	{
		j += (e->line[i] == '\t') ? 4 : 1;
		i--;
	}
	while (j-- > 0)
		write(1, " ", 1);
}

static inline void				trace_left(t_env *e)
{
	while (e->x-- > 0 && !is_end_param(e->line[e->x]))
		write(1, "~", 1);
}

static inline void				trace_right(t_env *e)
{
	while (!is_end_param(e->line[e->x++]))
		write(1, "~", 1);
}

void							trace(t_env *e)
{
	int		sav;

	e->x--;
	ft_putstr(COLOR_GREEN);
	put_blank(e);
	sav = e->x;
	trace_left(e);
	e->x = sav;
	trace_right(e);
	e->x = sav;
	ft_putendl(COLOR_END);
}
