/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:47:26 by agissing          #+#    #+#             */
/*   Updated: 2019/03/20 15:59:44 by jnoe             ###   ########.fr       */
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
# define COLOR_GREEN	"\e[32m"
# define COLOR_END		"\e[0m"
# define FONT_BOLD		"\e[1m"

# define SUFFIX			".cor"

# define NO_NAME_OR_COMMENT		1
# define BAD_PARAMETER			2
# define BAD_LABEL_NAME			3
# define BAD_PARAM_NUMBER		4
# define UNKNOWN_COMMAND		5
# define BAD_QUOTES				6
# define BAD_SYNTAXE			7
# define LABEL_NAME_EXIST		8
# define LIMIT_SIZE				9
# define CHAMPION_TO_BIG		10
# define CHAMPION_TO_SMALL		11

typedef	struct			s_todo
{
	char			*name;
	char			*op_pos;
	int				cursor;
	int				nb_oct;
	struct s_todo	*next;
}						t_todo;

typedef struct			s_mess
{
	char			*path;
	char			*name;
	char			*err;
	int				x;
	int				y;
	int				cmd;
}						t_mess;

typedef struct			s_label
{
	char			*name;
	char			*pos;
	struct s_label	*next;
}						t_label;

typedef struct			s_output
{
	t_header	header;
	char		champ[CHAMP_MAX_SIZE];
}						t_output;

typedef struct			s_env
{
	int			x;
	int			y;
	int			i;
	int			fd;
	int			ocp;
	int			true_l;
	int			index;
	char		*line;
	char		*path;
	char		*ocp_char;
	char		*op_char;
	t_label		*labels;
	t_todo		*to_put;
	t_output	data;
}						t_env;

/*
** Basics
*/
int						is_in_str(char c, char *str);
int						is_space(char c);
int						start_with(char *str, char c);
void					put_string_tab(t_env *e, char *str);

/*
** Errors
*/
void					p_error(t_env *e, int code);
void					e_error(int cond, int error_code);
void					custom_error(t_env *e, char *str, int code);

/*
** Trace
*/
void					trace(t_env *e);
void					put_blank(t_env *e);

/*
** Checks
*/
int						check_params(t_env *e, uint8_t enc, int count);
void					check_dir_ind(t_env *e, int direct);
void					check_reg(t_env *e);

/*
** Get commands name and comment
*/
int						get_name_comment(t_env *e);

/*
** Label
*/
void					add_new_label(t_env *e, char *name);
t_label					*label_exist(t_env *e, char *name);
int						label_to_put(t_env *e, int nb_oct);
void					put_label_pos(t_env *e);

/*
** Operators
*/
int						add_op(t_env *e, int index);
void					add_ind(t_env *e);
void					add_dir(t_env *e);
void					add_reg(t_env *e);

/*
** num_parser
*/
int						get_value(t_env *e, int nb_oct);

/*
** Free
*/
void					free_struct(t_env *e);

/*
** get_param
*/
int						get_param(t_env *e, int index);

/*
** get_op
*/
int						get_index(t_env *e);

/*
** overflow
*/
int						add_i(t_env *e);
void					add_to_champ(t_env *e, uint8_t octet);

/*
** get_label_name
*/
char					*get_label_name(t_env *e);

/*
** output
*/
void					put_output(t_env *e);

#endif
