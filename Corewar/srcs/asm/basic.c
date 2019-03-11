/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:20:39 by agissing          #+#    #+#             */
/*   Updated: 2019/03/11 17:12:34 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
//#include <sys/ioctl.h>

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
//	struct winsize	w;

//	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
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
//	e->x %= w.ws_col;
//	e->x %= atoi(getenv("COLUMNS"));
	write(1, "\n", 1);
}

void					add_to_champ(t_env *e, uint8_t octet)
{
	if (e->i <= CHAMP_MAX_SIZE)
		e->data.champ[e->i++] = octet;
	else
		p_error(e, CHAMPION_TO_BIG);
}
