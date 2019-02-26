/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:29:58 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/16 15:58:04 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdlib.h>

/* ************************************************************************** */

# include <stdio.h>

/* ************************************************************************** */

struct				s_node;

typedef struct		s_room
{
	char			*name;
	int				id;
	int				ant;
	struct s_node	*node;
	struct s_room	*next;
}					t_room;

typedef struct		s_tube
{
	char			*link;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_way
{
	t_room			*room;
	int				round;
	struct s_way	*next;
}					t_way;

typedef struct 		s_node
{
	t_room			*room;
	int				nb_next;
	struct s_node	*next;
}					t_node;

typedef struct		s_solve
{
	struct s_way	*path;
	int				nb;
	int				id;
	int				nb_ant;
	struct s_solve	*next;
}					t_solve;

typedef struct		s_round
{
	struct s_solve	*solve;
	int				steps;
	int				nb_paths;
	struct s_round	*next;
}					t_round;

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
	struct s_solve	*solve;
	struct s_round	*round;
	struct s_node	*node;
	void			***tab;
	int				error;
	int				tmp;
}					t_env;

// CHECK.C => 4
int					check_state(t_env *e, t_solve *tmp);
//static void		no_room_case(t_env *e);
void				check_basics(t_env *e);
void				check_ant_nb(t_env *e);

// FREE.C => 5
void				free_way(t_way *to_free);
//static void		free_tab(t_env *e);
//static void		free_tube_lst(t_env *e);
//static void		free_room_lst(t_env *e);
void				free_env(t_env *e, int error);

// INIT.C => 2
void				init_lst(t_env *e);
void				init_id(t_env *e);

// START_END.C => 3
//static t_room		*start_end_cmp(e, char *cmp);
int					add_end(t_env *e);
int					add_start(t_env *e);

// PRINT.C => 3
void				print_way(t_env *e);
void				print_lst(t_env *e);
void				print_tab(void ***tab, int size);
void				print_tab2(void ***tab, int size);
void				print_round(t_env *e);
// LST.C => 3
int					tube_lst(t_env *e, char *line);
//static t_room		*room_check(t_env *e, char *line);
int					room_lst(t_env *e, char *line);

// EXIT.C => 2
void				ft_exit(int error);
void				frexit(void *to_free, int error);

// SORT_INPUT.C => 4
//static void		hashtag_info(t_env *e, char *line);
//static int		start_end_info(t_env *e, char *line);
//static void		map_info(t_env *e, char *line);
void				sort_input(t_env *e);

// LINK.C => 3
//static void		fill_links_tab(t_env *e, t_room *addr1, t_room *addr2);
//static void		find_links(t_env *e, t_room *addr1, t_room *addr2);
int					create_link_tab(t_env *e);

// DELETE_CPY.C => 4
//static void		cpy_room(t_env *e, t_solve *new_solve, t_solve *ptr);
t_solve				*cpy_path(t_env *e, t_solve *ptr);
//static t_solve	*first_node_delete(t_env *e, t_solve *ptr);
t_solve				*delete_path(t_env *e, t_solve *ptr);

// WAY.C => 4
//static t_node		*create_lst(t_env *e, t_room *addr, int nb);
//static int		nb_next(t_env *e, int y);
//static void		get_next(t_env *e, t_node *ptr, int x);
void				find_path(t_env *e);

// SOLVING.C => 1
void				solve(t_env *e);

// SORT_OUTPUT.C => 9
//static void		sort_output(t_env *e);
//static inline int	is_end_start(t_env *e, t_room *room);
//static int		linked(t_env *e, t_solve *cmp1, t_solve *cmp2);
//static void		add_to_round(t_round *round, t_solve *way);
void				path_to_round(t_env *e, t_round *round, t_solve *way);
//static void		find_round(t_env *e, t_solve *ptr);
void				init_resolution(t_env *e);

//PRINT_TREE.C => 1

void				print_tree(t_node *tree);

#endif
