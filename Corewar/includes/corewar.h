/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:19:53 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/01 14:40:28 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"

typedef struct s_champion	t_champion;
typedef struct s_arena		t_arena;

typedef struct				s_map
{
	char					hex;
	int						color;
}							t_map;

struct						s_arena
{
	t_map					map[MEM_SIZE * 2 + 1];
	int						cycle;
	int						cycle_to_die;
	int						total_process;
	t_champion				*champion;
};

typedef struct				s_process
{
	t_map					*pc;
	int						idx_instruction;
	int						cycle_decount;
	int						size_instruction;
	t_champion				*champion;
	struct s_process		*next;
}							t_process;

struct						s_champion
{
	char					*name;
	int						number;
	int						last_live;
	int						period_live_nb;
	int						nb_process;
	t_process				*process;
	t_arena					*arena;
	struct s_champion		*next;
};

t_arena						*create_arena(int ac, char **av);

void						create_champ(char *file_name, t_map *map,
							int color, t_arena *arena);

void						ft_exit(void);

void						print_map(t_map *map);
void						print_structure(t_arena arena, t_map *map);
void						print_op_tab(t_arena *arena);

int							hex_to_int(char *str, char *base, int len);				

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
