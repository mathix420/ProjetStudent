/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:23:41 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/01 14:41:48 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, &ft_live, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, &ft_ld, 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, &ft_st, 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, &ft_add, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, &ft_sub, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		&ft_and, 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		&ft_or, 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		&ft_xor, 1, 0},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, &ft_zjmp, 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		&ft_ldi, 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		&ft_sti, 1, 1},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, &ft_fork, 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, &ft_lld, 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		&ft_lldi, 1, 1},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, &ft_lfork, 0, 1},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, &ft_aff, 1, 0},
	{0, 0, {0, 0, 0}, 0, 0, &ft_nothing, 0, 0}
};
