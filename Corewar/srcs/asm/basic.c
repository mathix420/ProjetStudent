/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:20:39 by agissing          #+#    #+#             */
/*   Updated: 2019/03/11 19:11:35 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

int						is_in_str(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int						start_with(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!is_space(str[i]))
			return (c == str[i]);
	return (0);
}

void					put_string_tab(t_env *e, char *str)
{
	int				i;
	int				max;

	i = -1;
	max = e->x;
	while (str[++i])
		if (str[i] != '\t')
			write(1, &str[i], 1);
		else
		{
			write(1, "    ", 4);
			if (max > i)
				e->x += 3;
		}
	write(1, "\n", 1);
}
