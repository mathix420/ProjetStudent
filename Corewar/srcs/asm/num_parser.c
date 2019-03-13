/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:34:42 by agissing          #+#    #+#             */
/*   Updated: 2019/03/13 16:18:28 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int		is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR
			|| c == ' ' || c == '\t' || c == '\v' || c == '\f');
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
			p_error(e, LIMIT_SIZE);
	}
	return ((uint32_t)out * (uint32_t)sign);
}
