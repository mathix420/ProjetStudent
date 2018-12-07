/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:01:11 by agissing          #+#    #+#             */
/*   Updated: 2018/11/24 16:06:35 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/* ------------------------------------------------ */
# include <stdio.h>
/* ------------------------------------------------ */

# include "libft.h"

typedef struct	s_cont
{
	int				*x;
	int				*y;
	struct s_cont	*next;
}				t_cont;

typedef struct	s_map;
{
	char	**map;
	int		area;
	int		size;
}				t_map;

int				ft_check(char *tetri);
void			ft_free_error(char **str);
void			ft_error(void);
void			ft_tetri_to_a(char **tetri, char a);
void			ft_create_node(t_cont **start, char *tetri);
void			ft_solve(t_cont *list, int nb_tetri);

/* ------------------------------------------------ */
void			ft_print_list(t_cont *list);
/* int				*ft_fpos(char *tetri); */
/* ------------------------------------------------ */
#endif
