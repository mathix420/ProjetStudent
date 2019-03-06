/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:21 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/06 10:57:13 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "corewar.h"

t_op    g_op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, 0, 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, 0, 1, 0, 2},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, 0, 1, 0, 2},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 0, 1, 0, 3},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 0, 1, 0, 3},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		0, 1, 0, 3},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		0, 1, 0, 2},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		0, 1, 0, 3},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, 0, 0, 1, 4},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		0, 1, 1, 3},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		0, 1, 1, 3},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, 0, 0, 1, 4},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, 0, 1, 0, 3},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		0, 1, 1, 4},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, 0, 0, 1, 5},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, 0, 1, 0, 3},
	{0, 0, {0, 0, 0}, 0, 0, 0, 0, 0, 0}
};
