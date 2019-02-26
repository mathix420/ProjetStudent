/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:44:49 by agissing          #+#    #+#             */
/*   Updated: 2019/02/11 19:26:48 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	solve(t_env *e)
{
	t_solve		*solve;

	solve = e->solve;
	while (solve && e->info.nb_ant)
	{
		
		solve = solve->next;
	}
}
