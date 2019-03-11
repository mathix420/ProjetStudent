/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:23:37 by agissing          #+#    #+#             */
/*   Updated: 2019/03/11 20:01:41 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//change .s en .cor
//si pas de .s alors met juste un .cor

static char				*dot_cor_name(t_env *e)
{
	int		i;
	int		size;
	char	*out;
	char	suffix[4];

	i = 0;
	suffix[0] = '.';
	suffix[1] = 'c';
	suffix[2] = 'o';
	suffix[3] = 'r';
	while (e->path[i])
		i++;
	size = i;
	while (e->path[i] && e->path[i] != '.' && e->path[i] != '/')
		i--;
	(e->path[i] != '.') ? (i = size) : 0;
	size = i;
	e_error((out = ft_strnew(i + 2 + (e->path[i] != '.'))) == NULL, 0);
	i = -1;
	while (++i < size)
		out[i] = e->path[i];
	i--;
	size = (e->path[i] != '.');
	while (size < 4)
		out[i++] = suffix[size++];
	printf("NAME :: '%s'\n", out);
	return (out);
}

void					put_output(t_env *e)
{
	int		fd;
	char	*filename;

	filename = dot_cor_name(e);
	e_error((fd = open(filename, O_WRONLY)) < 0, 0);
	free(filename);
	e_error(write(fd, (char *)&e->data, sizeof(t_header) + e->i) < 0, 0);
	close(fd);
}
