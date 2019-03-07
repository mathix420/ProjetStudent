/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:47:26 by agissing          #+#    #+#             */
/*   Updated: 2019/03/07 20:32:43 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# define COLOR_RED		"\e[91m"
# define COLOR_GREEN	"\e[92m"
# define COLOR_END		"\e[0m"

# define NO_NAME_OR_COMMENT 1
# define BAD_PARAMETER 2
# define BAD_LABEL_NAME 3
# define BAD_PARAM_NUMBER 4
# define UNKNOWN_COMMAND 5
# define BAD_QUOTES 6
# define BAD_SYNTAXE 7

typedef struct			s_output
{
	t_header	header;
	char		champ[CHAMP_MAX_SIZE];
}						t_output;

typedef struct			s_env
{
	int			true_l;
	char		*line;
	t_output	data;
	int			x;
	int			y;
}						t_env;

/*
** Basics
*/
int						is_in_str(char c, char *str);
int						is_space(char c);
int                     start_with(char *str, char c);

/*
** Errors
*/
void					p_error(t_env *e, int code);
void					e_error(int cond, int error_code);

/*
** Checks
*/
int						check_params(t_env *e, uint8_t enc);
void					check_dir_ind(t_env *e, int direct);
void					check_reg(t_env *e);

/*
** Get commands name and comment
*/
int						get_name_comment(t_env *e);

#endif
