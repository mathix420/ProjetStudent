/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:59:24 by agissing          #+#    #+#             */
/*   Updated: 2019/03/11 18:59:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				get_index(t_env *e)
{
	int		i;
	int		tmp;
	int		blank;
	int		max_size;

	i = -1;
	tmp = e->x;
	blank = 0;
	max_size = ft_strlen(e->line);
	while (g_op_tab[++i].name)
	{
		e->x = tmp + g_op_tab[i].name_size;
		if (e->x < max_size && is_space(e->line[e->x])
		&& !ft_strncmp(g_op_tab[i].name, e->line + tmp, g_op_tab[i].name_size))
			return (add_op(e, i));
	}
	e->x = tmp;
	return (-1);
}
