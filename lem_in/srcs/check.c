/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:35:00 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 17:52:26 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_coor(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line[len])
		len++;
	if (line[0] == 'L')
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	(line[i] == ' ') ? i++ : 1;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i++] != ' ')
		return (0);
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == len)
		return (1);
	return (0);
}

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
}

void		check_ant_nb(t_env *e)
{
	char	*line;
	int		i;

	i = -1;
	e->info.nb_ant = 0;
	(get_next_line(0, &line) <= 0 || !line[0]) ? ft_exit(4) : 1;
	while (line[++i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			if (e->info.nb_ant * 10 + (line[i] - 48) > 2147483647)
				frexit(line, 4);
			else
				e->info.nb_ant = e->info.nb_ant * 10 + (line[i] - 48);
		}
		else
			frexit(line, 4);
	}
	(e->info.nb_ant <= 0) ? frexit(line, 4) : 1;
	if (!(keep_map_in_buff(e, line)))
	{
		free(line);
		ft_exit(1);
	}
	free(line);
}
