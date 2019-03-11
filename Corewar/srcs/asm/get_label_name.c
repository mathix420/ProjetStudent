/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:37:44 by agissing          #+#    #+#             */
/*   Updated: 2019/03/11 19:38:15 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char					*get_label_name(t_env *e)
{
	char	*out;
	int		j;

	j = 0;
	e->x = 0;
	while (e->line[e->x] && e->line[e->x] != LABEL_CHAR
				&& is_in_str(e->line[e->x], LABEL_CHARS))
		e->x++;
	if (e->line[e->x] != LABEL_CHAR)
		p_error(e, BAD_LABEL_NAME);
	if (!(out = ft_strnew(e->x)))
		return (NULL);
	return (ft_strncpy(out, e->line, e->x));
}
