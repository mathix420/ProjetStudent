/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:35:00 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/17 14:47:38 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
int			check_state(t_env *e, t_solve *tmp)
{
	int			size;
	int			i;

	size = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->nb == e->info.nb_room - 1)
			i++;
		size++;
		tmp = tmp->next;
	}
	if (i == size)
		return (1);
	else
		return (0);
}

*/
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
		if (line[i] < '0' || line[i] > '9')
			frexit(line, 4);
	i = 0;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		e->info.nb_ant = e->info.nb_ant * 10 + (line[i++] - 48);
	if (e->info.nb_ant <= 0)
		frexit(line, 4);
	free(line);
}
