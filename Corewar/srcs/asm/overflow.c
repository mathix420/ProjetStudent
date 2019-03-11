/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:04:50 by agissing          #+#    #+#             */
/*   Updated: 2019/03/11 19:18:46 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						add_i(t_env *e)
{
	if (e->i >= CHAMP_MAX_SIZE)
		p_error(e, CHAMPION_TO_BIG);
	return (e->i++);
}

void					add_to_champ(t_env *e, uint8_t octet)
{
	if (e->i <= CHAMP_MAX_SIZE)
		e->data.champ[e->i++] = octet;
	else
		p_error(e, CHAMPION_TO_BIG);
}
