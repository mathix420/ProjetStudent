/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:35:00 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/23 14:38:54 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* static void	no_room_case(t_env *e) */
/* { */

/* } */

void		check_basics(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!e->info.start[0] || !e->info.end[0])
		free_env(e, 1);
	while (e->info.start[i] && e->info.start[i] != ' ')
		i++;
	while (e->info.end[j] && e->info.end[j] != ' ')
		j++;
	if (i == j)
		if (!ft_strncmp(e->info.start, e->info.end, i))
			free_env(e, 1);
	//	if (!e->info.nb_room)
	//		no_room_case(e);
}

void		check_ant_nb(t_env *e)
{
	char	*line;
	int		i;

	i = -1;
	e->info.nb_ant = 0;
	if (get_next_line(0, &line) <= 0 || !line[0])
		ft_exit(4);
	while (line[++i])
	{
		if (line[i] >= '0' && line[i] <= '9')
			e->info.nb_ant = e->info.nb_ant * 10 + (line[i] - 48);
		else
			frexit(line, 4);
	}
	if (e->info.nb_ant <= 0)
		frexit(line, 4);
	free(line);
}
