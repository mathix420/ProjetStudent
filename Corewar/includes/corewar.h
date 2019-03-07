/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:19:53 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/06 16:12:44 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"

typedef struct s_champion	t_champion;
typedef struct s_arena		t_arena;

typedef struct				s_param
{
	int						type;
	int						value;
}							t_param;

typedef struct				s_map
{
	char					hex;
	int						color;
}							t_map;

struct						s_arena
{
	t_map					map[MEM_SIZE * 2 + 1];
	int						dump;
	int						number_champs[4];
	int						arg_champ[4];
	int						nb_champs;
	int						cycle;
	int						cycle_to_die;
	int						total_process;
	t_champion				*champion;
	t_process				*process;
};

typedef struct				s_process
{
	t_map					*pc;
	int						registre[REG_NUMBER];
	t_param					param[3];
	int						valid_encodage;
	int						encodage;
	int						cycle_decount;
	int						index;
	int						size_instruction;
	t_arena					*arena;
	struct s_process		*next;
}							t_process;

struct						s_champion
{
	char					*name;
	char					*comment;
	int						size_instructions;
	int						number;
	int						last_live;
	int						period_live_nb;
	t_arena					*arena;
	struct s_champion		*next;
};

t_arena						*create_arena(int ac, char **av);

void						create_champ(char *file_name, t_map *map,
							int color, t_arena *arena);

void						ft_exit_parsing(int	error, char *file_name);
void						ft_exit_size(int error, char *file_name, int size);
void						ft_exit_usage(void);
void						ft_exit(void);

void						print_map(t_map *map);
void						print_structure(t_arena arena, t_map *map);
void						print_op_tab(t_arena *arena);

int							convert_to_int(unsigned char *str);
int							hex_to_int(char *str, char *base, int len);				


void						get_current_instruction(t_process *process);
void						get_param_instruction(t_process *process);
void						check_encodage(t_process *process);
int							no_encodage_needed(t_process *process);

void						parsing_size_file(char *file_name);
void						parsing_exec_magic(int fd, char *file_name);
void						parsing_name(int fd, t_champion *champion, char *file_name);
void						parsing_champ(char *file_name, t_champion *champion);

void						parsing_arguments(int ac, char **av, t_arena *arena);

void						ft_live(t_process *process);
void						ft_ld(t_process *process);
void						ft_st(t_process *process);
void						ft_add(t_process *process);
void						ft_sub(t_process *process);
void						ft_and(t_process *process);
void						ft_or(t_process *process);
void						ft_xor(t_process *process);
void						ft_zjmp(t_process *process);
void						ft_ldi(t_process *process);
void						ft_sti(t_process *process);
void						ft_fork(t_process *process);
void						ft_lld(t_process *process);
void						ft_lldi(t_process *process);
void						ft_lfork(t_process *process);
void						ft_aff(t_process *process);
void						ft_nothing(t_process *process);

#endif
