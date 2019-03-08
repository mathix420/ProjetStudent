/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:05:16 by agissing          #+#    #+#             */
/*   Updated: 2019/03/08 18:11:48 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define REGISTRE				1 << 6
# define DIRECT					1 << 7
# define INDIRECT				3 << 6

typedef struct					s_header
{
	char						magic[sizeof(COREWAR_EXEC_MAGIC)];
	char						prog_name[PROG_NAME_LENGTH + 4];
	char						prog_size[4];
	char						comment[COMMENT_LENGTH + 4];
}								t_header;

typedef char					t_arg_type;
typedef struct s_process		t_process;

typedef struct					s_op
{
	char				*name;
	int					nb_param;
	unsigned char		encodage[3];
	int					op_code;
	int					duration;
	void				(*function)(t_process *);
	int					carry;
	int					direct_size;
	int					name_size;
	int					ocp;
}								t_op;

# ifdef MAIN_FILE

extern t_op						g_op_tab[17];

# else

t_op							g_op_tab[17];

# endif
#endif
