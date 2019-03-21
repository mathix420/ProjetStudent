/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:04:45 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/20 16:11:30 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "corewar.h"

void			print_winner(t_arena *arena, t_champion *winner)
{
	int			i;
	t_champion	*champion;

	i = 1;
	champion = arena->champion;
	while (champion != winner)
	{
		i++;
		champion = champion->next;
	}
	ft_putstr("Contestant ");
	ft_putnbr(i);
	ft_putstr(", \"");
	ft_putstr(winner->name);
	ft_putstr("\", has won !\n");
}

t_champion		*winner(t_arena *arena)
{
	t_champion	*champion;
	t_champion	*winner;

	champion = arena->champion;
	winner = champion;
	while (champion)
	{
		if (winner->last_live <= champion->last_live)
			winner = champion;
		champion = champion->next;
	}
	champion = arena->champion;
	while (champion)
	{
		if (winner->last_live == champion->last_live
				&& winner->last_alive < champion->last_alive)
			winner = champion;
		champion = champion->next;
	}
	return (winner);
}
