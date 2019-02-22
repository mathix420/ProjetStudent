/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:26:55 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/17 14:45:20 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		hashtag_info(t_env *e, char *line)
{
	char	*cmp1;
	char	*cmp2;

	cmp1 = "##start\0";
	cmp2 = "##end\0";
	if (!ft_strncmp(cmp1, line, 7))
		e->info.start_id = -2;
	else if (!ft_strncmp(cmp2, line, 5))
		e->info.end_id = -2;
}

static int		start_end_info(t_env *e, char *line)
{
	char	*tmp;

	if (e->tube)
		return (0);
	else if (e->info.space == 2 && !e->info.dash && e->info.start_id == -2)
	{
		tmp = e->info.start;
		e->info.start = ft_strdup(line);
		e->info.start_id = -1;
	}
	else if (e->info.space == 2 && !e->info.dash && e->info.end_id == -2)
	{
		tmp = e->info.end;
		e->info.end = ft_strdup(line);
		e->info.end_id = -1;
	}
	else
		return (0);
	free(tmp);
	return (1);
}

static void		map_info(t_env *e, char *line)
{
	int		i;

	i = -1;
	e->info.dash = 0;
	e->info.space = 0;
	while (line[++i])
	{
		(line[i] == '-') ? e->info.dash++ : 1;
		(line[i] == ' ') ? e->info.space++ : 1;
	}
	if (start_end_info(e, line))
		return ;
	else if (e->info.space == 2 && !e->info.dash)
	{
		if (!(room_lst(e, line)))
			e->error = 1;
	}
	else if (e->info.dash == 1 && !e->info.space)
	{
		if (!(tube_lst(e, line)))
			free_env(e, 1);
	}
	else
		e->error = 1;
}

void			sort_input(t_env *e)
{
	char	*line;

	check_ant_nb(e);
	init_lst(e);
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
			hashtag_info(e, line);
		else
			map_info(e, line);
		if (!line[0] || e->error)
		{
			free(line);
			break ;
		}
		free(line);
	}
	check_basics(e);
	if (!add_start(e) || !add_end(e))
		ft_exit(0);
	init_id(e);
	(!(create_link_tab(e))) ? ft_exit(0) : 1;
	(!e->info.nb_link) ? ft_exit(1) : 1;
}
