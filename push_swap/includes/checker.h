/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:53 by agissing          #+#    #+#             */
/*   Updated: 2019/01/10 17:18:40 by agissing         ###   ########.fr       */
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
	void    *mlx;
	void    *win;
	void    *img;
	t_stack *pila;
	t_stack *pilb;
	int		*str;
	int		siz_x;
	int		siz_y;
	int		color;
	int		ep;
	int		step;
	t_op	*op;
}				t_mlx;

#endif
