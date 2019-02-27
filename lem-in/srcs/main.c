/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:30:52 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/27 15:23:38 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(void)
{
	t_env		e;
	int			break_solve;

	e.buff = NULL;
	break_solve = 0;
	check_ant_nb(&e);
	init_list(&e);
	sort_input(&e);
	if (!(e.tree = init_tree(&e)))
		free_env(&e, 3);
	init_solve(&e, break_solve);
	if (e.best_steps != -2)
	{
		clean_to_restart(&e);
		init_solve(&e, break_solve + 1);
		print_buff(&e);
		print_solution(&e);
	}
	else
		write(1, "ERROR\n", 6);
	free_env(&e, 0);
	return (0);
}
