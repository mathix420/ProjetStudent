/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:30:52 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/17 14:54:26 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(void)
{
	t_env		e;

	sort_input(&e); //rapide
//	print_lst(&e);
//	printf("=================================================\n\n\n");
//	print_tab2(e.tab, e.info.nb_room);
	if (!(e.tree = init_tree(&e)))
		return (1);
//	find_path(&e); //lent
//	init_resolution(&e); //0.006 sec
//	print_way(&e);
	free_env(&e, 0); //rapide
	return (0);
}
