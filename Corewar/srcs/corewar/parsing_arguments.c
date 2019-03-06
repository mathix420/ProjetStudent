/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:12:13 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/06 17:12:42 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		number_of_champion(int tab[4], int nb_champ)
{
	int	nb;
	int	i;

	if (nb_champ == 0)
		return (1);
	nb = 1;
	i = -1;
	while (++i < nb_champ)
	{
		if (nb == tab[i])
		{
			nb++;
			i = -1;
		}
	}
	return (nb);
}

int		ft_str_is_nbr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parsing_dump(char **av, t_arena *arena, int *i)
{
	if (av[*i] && !ft_strcmp(av[*i], "-dump"))
	{
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

void	parsing_arguments(int ac, char **av, t_arena *arena)
{
	int i;
	int	nb_champ;

	(void)ac;
	i = 1;
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
