/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:30:52 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/23 18:01:13 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(void)
{
	t_env		e;

	e.buff = NULL;
	check_ant_nb(&e);
	init_lst(&e);
	sort_input(&e);
	if (!(e.tree = init_tree(&e)))
		return (1);
	init_resolution(&e);
//	print_buff(&e);
	free_env(&e, 0);
	return (0);
}
