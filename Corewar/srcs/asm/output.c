/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:23:37 by agissing          #+#    #+#             */
/*   Updated: 2019/03/17 17:48:00 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char				*dot_cor_name(t_env *e)
{
	int		i;
	int		size;
	char	*out;

	i = ft_strlen(e->path) - 1;
	size = i + 1;
	while (i >= 0 && e->path[i] != '.' && e->path[i] != '/')
		i--;
	if (e->path[i] == '.')
		size = i;
	e_error((out = ft_strnew(size + 4)) == NULL, 0);
	i = -1;
	while (++i < size)
		out[i] = e->path[i];
	size = 0;
	while (size < 4)
		out[i++] = SUFFIX[size++];
	return (out);
}

void					put_output(t_env *e)
{
	int		fd;
	char	*filename;

	if (!e->data.header.prog_name[0] || !e->data.header.comment[0])
		p_error(e, NO_NAME_OR_COMMENT);
	if (!e->i)
		p_error(e, CHAMPION_TO_SMALL);
	filename = dot_cor_name(e);
	e_error((fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0, 0);
	e_error(write(fd, (char *)&e->data, sizeof(t_header) + e->i) < 0, 0);
	close(fd);
	ft_putstr("Writing output program to ");
	ft_putendl(filename);
	ft_strdel(&filename);
}
