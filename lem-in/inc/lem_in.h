/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:29:58 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/20 18:08:06 by agissing         ###   ########.fr       */
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
	struct s_node	*node;
	struct s_room	*next;
}					t_room;

typedef struct 		s_node
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
	int				*tab_size;
	int				id_way;
	int				steps;
	int				error;
	t_room			*end_ptr;
}					t_env;
// FREE.C => 4
//static void		free_tab(t_env *e);
//static void		free_tube_lst(t_env *e);
//static void		free_room_lst(t_env *e);
void				free_env(t_env *e, int error);

// CHECK.C => 2
void				check_basics(t_env *e);
void				check_ant_nb(t_env *e);

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

/*
//PRINT_TREE.C => 1
void				print_tree(t_node *tree);
*/

// RESOLVE.C
int					solve(t_env *e, t_node *node, int steps);
void				init_resolution(t_env *e);

//QUEUE.C => 2
int					enqueue(t_env *e, t_node *elmt);
void				dequeue(t_env *e);

//TREE.C => 2
//static t_node		*create_node(t_env *e, t_room *room);
t_node				*init_tree(t_env *e);
void				build_tree(t_env *e);

//BFS.C => 2
void				clean_depth(t_env *e);
void				bfs(t_env *e, t_node *start, int id);
void				trace_new_path(t_env *e, t_node *start, int id);
#endif
