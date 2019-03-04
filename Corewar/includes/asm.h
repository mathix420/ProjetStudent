/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:47:26 by agissing          #+#    #+#             */
/*   Updated: 2019/03/04 22:09:37 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "op.h"

# include "libft.h"

# define COLOR_RED		"\e[91m"
# define COLOR_GREEN	"\e[92m"
# define COLOR_END		"\e[0m"

typedef struct		s_op
{
	char	*name;
	char	val;
	int		check[3];
}					t_op;

t_op			op_tab[17] =
{
	{"live", 0x01, {T_DIR, 0, 0}},
	{"ld", 0x02, {T_DIR | T_IND, T_REG, 0}},
	{"st", 0x03, {T_REG, T_IND | T_REG, 0}},
	{"add", 0x04, {T_REG, T_REG, T_REG}},
	{"sub", 0x05, {T_REG, T_REG, T_REG}},
	{"and", 0x06, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}},
	{"or", 0x07, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
	{"xor", 0x08, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
	{"zjmp", 0x09, {T_DIR, 0, 0}},
	{"ldi", 0x0a, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
	{"sti", 0x0b, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}},
	{"fork", 0x0c, {T_DIR, 0, 0}},
	{"lld", 0x0d, {T_DIR | T_IND, T_REG, 0}},
	{"lldi", 0x0e, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
	{"lfork", 0x0f, {T_DIR, 0, 0}},
	{"aff", 0x10, {T_REG, 0, 0}},
	{NULL, 0, {0, 0, 0}}
};

# define NO_NAME_OR_COMMENT 1

#endif
