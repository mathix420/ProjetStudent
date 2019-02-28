/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:29:58 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/28 17:55:04 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdlib.h>

struct s_node;

typedef struct		s_tube
{
	char			*link;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	int				id;
	int				depth;
	int				nb_ant;
	int				old_ant;
	int				lock;
	struct s_node	*node;
	struct s_room	*next;
}					t_room;

typedef struct		s_node
{
	t_room			*room;
	int				nb_next;
	struct s_node	**next;
}					t_node;

typedef struct		s_queue
{
	t_node			*node;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_buff
{
	char			str[5000];
	int				i;
	struct s_buff	*next;
}					t_buff;

typedef struct		s_result
{
	char			*id;
	int				int_id;
	char			*room;
	int				room_id;
	int				arrived;
	struct s_result	*next;
}					t_result;

typedef struct		s_info
{
	int				nb_ant;
	int				nb_room;
	int				nb_link;
	int				nb_path;
	int				start_id;
	int				end_id;
	int				dash;
	int				space;
	char			*comment;
	char			*start;
	char			*end;
}					t_info;

typedef struct		s_env
{
	struct s_room	*room;
	struct s_tube	*tube;
	struct s_info	info;
	struct s_node	*tree;
	struct s_queue	*queue;
	struct s_queue	*end_queue;
	struct s_room	***tab;
	struct s_buff	*buff;
	struct s_result	*res;
	int				*tab_size;
	int				*tab_ant;
	int				*tab_id;
	int				steps;
	int				best_steps;
	int				best_call;
	int				solve_id;
	int				error;
	int				count;
	int				lock_var;
}					t_env;

void				free_env(t_env *e, int error);
int					check_coor(char *line);
void				check_basics(t_env *e);
void				check_ant_nb(t_env *e);
void				init_list(t_env *e);
void				init_id(t_env *e);
void				cut_room_name(t_env *e);
int					add_end(t_env *e);
int					add_start(t_env *e);
int					tube_list(t_env *e, char *line);
int					room_list(t_env *e, char *line);
void				ft_exit(int error);
void				frexit(void *to_free, int error);
void				sort_input(t_env *e);
int					create_link_tab(t_env *e);
int					clean_count(t_env *e);
void				clean_depth(t_env *e);
void				clean_to_restart(t_env *e);
void				clean_ant(t_env *e);
void				clean_unused_path(t_env *e);
void				init_solve(t_env *e, int break_solve);
int					enqueue(t_env *e, t_node *elmt);
void				dequeue(t_env *e);
void				clear_queue(t_env *e);
t_node				*init_tree(t_env *e);
int					bfs(t_env *e, t_node *start, int id);
void				print_buff(t_env *e);
int					keep_map_in_buff(t_env *e, char *line);
void				print_result_list(t_env *e);
void				listing_res(t_env *e, int id_ant, char *room, int room_id);
void				print_solution(t_env *e);

#endif
