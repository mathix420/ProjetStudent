/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:30:52 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 20:48:29 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(void)
{
	t_env		e;
	int			y;
	int			x;

	y = -1;
	x = -1;
	sort_input(&e);
	print_lst(&e);
	print_tab(e.tab, e.info.nb_room);
	find_path(&e);
	free_env(&e);
	return (0);
}
