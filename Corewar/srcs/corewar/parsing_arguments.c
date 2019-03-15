/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:12:13 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/15 18:10:53 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parsing_dump(char **av, t_arena *arena, int *i)
{
	if (av[*i] && !ft_strcmp(av[*i], "-dump"))
	{
		if (arena->dump != -1 || arena->graphic == 1)
			ft_exit_usage();
		(*i)++;
		if (av[*i] && ft_str_is_nbr(av[*i]))
		{
			arena->dump = ft_atoi(av[*i]);
			(*i)++;
		}
		else
			ft_exit_usage();
	}
}

void	parsing_ncurse(char **av, t_arena *arena, int *i)
{
	if (av[*i] && !ft_strcmp(av[*i], "-v"))
	{
		if (arena->dump != -1)
			ft_exit_usage();
		(*i)++;
		arena->graphic = 1;
	}
}

void	parsing_nb_champ(char **av, t_arena *arena, int *i, int nb_champ)
{
	if (av[*i] && !ft_strcmp(av[*i], "-n"))
	{
		(*i)++;
		if (av[*i] && ft_str_is_nbr(av[*i]))
		{
			arena->number_champs[nb_champ] = ft_atoi(av[*i]);
			(*i)++;
		}
		else
			ft_exit_usage();
	}
	else if (av[*i])
		arena->number_champs[nb_champ] = number_of_champion(
				arena->number_champs, nb_champ);
}

void	parsing_arg_champ(char **av, t_arena *arena, int *i, int nb_champ)
{
	if (nb_champ > MAX_PLAYERS)
		ft_exit_usage();
	parsing_nb_champ(av, arena, i, nb_champ - 1);
	if (!av[*i])
		ft_exit_usage();
	else if (!ft_strcmp(av[*i], "-n"))
		ft_exit_usage();
	arena->arg_champ[nb_champ - 1] = *i;
}

void	parsing_arguments(char **av, t_arena *arena)
{
	int i;
	int	nb_champ;

	i = 1;
	parsing_dump(av, arena, &i);
	parsing_ncurse(av, arena, &i);
	parsing_dump(av, arena, &i);
	nb_champ = 0;
	while (av[i])
	{
		nb_champ++;
		parsing_arg_champ(av, arena, &i, nb_champ);
		i++;
	}
	arena->nb_champs = nb_champ;
	if (arena->nb_champs < 1)
		ft_exit_usage();
}
