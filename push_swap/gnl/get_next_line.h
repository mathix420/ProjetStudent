/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:39:32 by agissing          #+#    #+#             */
/*   Updated: 2019/01/04 14:14:23 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"

# define GNL_BUFF_SIZE 32

typedef struct	s_file
{
	int				fd;
	char			*sav;
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
