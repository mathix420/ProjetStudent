/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:01:05 by agissing          #+#    #+#             */
/*   Updated: 2019/03/06 17:34:48 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int		is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR
			|| c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

void					check_dir_ind(char *param, int direct)
{
	int		i;
	int		label;

	i = !!direct;
	label = (param[i] == LABEL_CHAR);
	i += label;
	if (!label && (param[i] == '-' || param[i] == '+'))
		i++;
	while (!is_end_param(param[i]))
	{
		if ((label && !is_in_str(param[i], LABEL_CHARS))
			|| (!label && (param[i] < '0' || param[i] > '9')))
			p_error(i + 1, param, BAD_PARAMETER);
		i++;
	}
}

void					check_reg(char *param)
{
	int		i;

	i = 0;
	while (!is_end_param(param[++i]))
		if (param[i] < '0' || param[i] > '9')
			p_error(i + 1, param, BAD_PARAMETER);
}
