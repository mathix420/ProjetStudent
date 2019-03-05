/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:47:26 by agissing          #+#    #+#             */
/*   Updated: 2019/03/05 13:01:00 by agissing         ###   ########.fr       */
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

# define NO_NAME_OR_COMMENT 1

void						ft_live(t_arena *arena);
void						ft_ld(t_arena *arena);
void						ft_st(t_arena *arena);
void						ft_add(t_arena *arena);
void						ft_sub(t_arena *arena);
void						ft_and(t_arena *arena);
void						ft_or(t_arena *arena);
void						ft_xor(t_arena *arena);
void						ft_zjmp(t_arena *arena);
void						ft_ldi(t_arena *arena);
void						ft_sti(t_arena *arena);
void						ft_fork(t_arena *arena);
void						ft_lld(t_arena *arena);
void						ft_lldi(t_arena *arena);
void						ft_lfork(t_arena *arena);
void						ft_aff(t_arena *arena);
void						ft_nothing(t_arena *arena);

#endif
