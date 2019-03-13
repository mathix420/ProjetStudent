/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:37:44 by agissing          #+#    #+#             */
/*   Updated: 2019/03/13 14:52:38 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char					*get_label_name(t_env *e)
{
	char	*out;
	int		offset;
	int		j;

	j = 0;
	offset = 0;
	while (e->line[offset] && is_space(e->line[offset]))
		offset++;
	e->x = offset;
	while (e->line[e->x] && e->line[e->x] != LABEL_CHAR
				&& is_in_str(e->line[e->x], LABEL_CHARS))
		e->x++;
	if (e->line[e->x] != LABEL_CHAR)
		p_error(e, BAD_LABEL_NAME);
	if (!(out = ft_strnew(e->x - offset)))
		return (NULL);
	return (ft_strncpy(out, e->line + offset, e->x - offset));
}
