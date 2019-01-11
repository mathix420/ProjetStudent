/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:53 by agissing          #+#    #+#             */
/*   Updated: 2019/01/11 14:49:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "stack.h"
# include "mlx.h"

typedef struct	s_off
{
	int		x;
	int		y;
}				t_off;

typedef struct	s_op
{
	int			nb;
	struct s_op	*next;
}				t_op;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	t_stack *pila;
	t_stack *pilb;
	int		*str;
	int		siz_x;
	int		siz_y;
	int		color;
	int		ep;
	int		step;
	t_op	*op;
	int		len;
	int		opt;
}				t_mlx;

void			ft_init(t_mlx *mlx, t_stack *stck_a, t_stack *stck_b);
void			ligne(t_mlx *mlx, t_off off, int ep, int len);
void			ft_get_op(t_op **op);
int				ft_add(t_op **op, char *ops);
void			ft_add_op(t_op **op, int nb);
t_op			*ft_do_op(t_mlx *mlx);
void			print_both(t_mlx *mlx);
int				treat(t_mlx *mlx);
int				ft_max(t_stack *pile);
int				ft_len(t_stack *pile);

#endif
