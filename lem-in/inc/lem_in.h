/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acompagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:29:58 by acompagn          #+#    #+#             */
/*   Updated: 2019/02/10 20:30:16 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_room
{
	char			*name;
	int				id;
	int				ant;
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

typedef struct		s_solve
{
	struct s_way	*path;
	int				nb;
	struct s_solve	*next;
}					t_solve;

typedef struct		s_info
{
	int				nb_ant;
	int				nb_room;
	int				nb_link;
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
	void			***tab;
	int				error;
}					t_env;

// CHECK.C => 4
//static void		no_room_case(t_env *e);
void				check_basics(t_env *e);
void				check_ant_nb(t_env *e);

// FREE.C => 1
void				free_env(t_env *e);

// INIT.C => 2
void				init_lst(t_env *e);
void				init_id(t_env *e);

// PRINT.C => 2
void				print_lst(t_env *e);
void				print_tab(void ***tab, int size);

// LST.C => 5
int					tube_lst(t_env *e, char *line);
//static t_room		*room_check(t_env *e, char *line);
int					add_start(t_env *e);
int					add_end(t_env *e);
int					room_lst(t_env *e, char *line);

// EXIT.C => 2
void				free_tab(t_env *e);
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

// WAY.C => 2
void				create_lst(t_env *e, t_room *addr);
void				find_path(t_env *e);

#endif
