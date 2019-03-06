/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:01:21 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/06 16:11:59 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "corewar.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, &ft_live, 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, &ft_ld, 1, 0, 2},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, &ft_st, 1, 0, 2},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, &ft_add, 1, 0, 3},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, &ft_sub, 1, 0, 3},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		&ft_and, 1, 0, 3},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		&ft_or, 1, 0, 2},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		&ft_xor, 1, 0, 3},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, &ft_zjmp, 0, 1, 4},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		&ft_ldi, 1, 1, 3},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		&ft_sti, 1, 1, 3},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, &ft_fork, 0, 1, 4},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, &ft_lld, 1, 0, 3},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		&ft_lldi, 1, 1, 4},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, &ft_lfork, 0, 1, 5},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, &ft_aff, 1, 0, 3},
	{0, 0, {0, 0, 0}, 0, 0, &ft_nothing, 0, 0, 0}
};
