/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:35:00 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 20:37:48 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
static void	no_room_case(t_env *e)
{

}*/

void		check_basics(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!e->info.start[0] || !e->info.end[0])
		ft_exit(2);
	while (e->info.start[i] && e->info.start[i] != ' ')
		i++;
	while (e->info.end[j] && e->info.end[j] != ' ')
		j++;
	if (i == j)
		if (!ft_strncmp(e->info.start, e->info.end, i))
			ft_exit(3);
//	if (!e->info.nb_room)
//		no_room_case(e);
}

void		check_ant_nb(t_env *e)
{
	char	*line;
	int		i;

	i = -1;
	if (get_next_line(0, &line) <= 0 || !ft_strlen(line))
		frexit(line, 4);
	while (line[++i])
		if (line[i] < '0' || line[i] > '9')
			frexit(line, 4);
	i = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		e->info.nb_ant = e->info.nb_ant * 10 + (line[i++] - 48);
	if (e->info.nb_ant <= 0)
		frexit(line, 4);
	free(line);
}
