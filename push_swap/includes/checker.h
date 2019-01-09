/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:04:53 by agissing          #+#    #+#             */
/*   Updated: 2019/01/09 22:03:00 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "stack.h"
# include "mlx.h"

typedef struct	s_mlx
{
	void    *mlx;
	void    *win;
	int		siz_x;
	int		siz_y;
	int		color;
}				t_mlx;

typedef struct	s_off
{
	int		x;
	int		y;
}				t_off;

#endif
