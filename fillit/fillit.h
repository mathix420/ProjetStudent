/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:01:11 by agissing          #+#    #+#             */
/*   Updated: 2018/11/27 19:13:41 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_cont
{
	uint16_t		tetri;
	uint8_t			x;
	uint8_t			y;
	uint8_t			width;
	uint8_t			height;
	struct s_cont	*next;
}				t_cont;

typedef struct	s_map
{
	uint32_t	max;
	uint8_t		size;
	uint16_t	*map;
}				t_map;

int				ft_check(char *tetri);
t_map			*ft_map(void);
void			ft_mapzero(void *s);
int				ft_read(int fd, t_cont **list);
void			ft_error(void);
uint16_t		ft_tetri_to_b(char *tetri);
int				ft_first_square(int nb);
int				ft_place_tetri(t_cont tetri, t_map *map);
t_cont			*ft_create_node(t_cont **start);
int				ft_solve(t_cont *list, int nb);
uint16_t		reverse_bits(uint16_t nb);
void			display(t_cont *tetri, int size);

#endif
