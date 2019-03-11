/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:12:00 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/11 20:01:59 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int				parse(t_env *e)
{
	char	*tmp;
	int		id;
	int		space;

	e->x = -1;
	space = 0;
	if (e->true_l < 2)
		return (get_name_comment(e));
	while (e->line[++e->x] && e->line[e->x] != COMMENT_CHAR)
		if (e->line[e->x] == LABEL_CHAR)
		{
			if (e->x == 0)
				p_error(e, BAD_LABEL_NAME);
			else if (e->line[e->x - 1] != DIRECT_CHAR
				&& (tmp = get_label_name(e)))
				(space = 0) ? 0 : add_new_label(e, tmp);
		}
		else if (!space && (id = get_index(e)) != -1)
			return (1);
		else if (!is_space(e->line[e->x]))
			space = 1;
		else if (id < -1 || space)
			p_error(e, UNKNOWN_COMMAND);
	(space) ? p_error(e, UNKNOWN_COMMAND) : 0;
	return (0);
}

static void				put_magic(t_env *e)
{
	int		i;
	int		j;
	int		size;

	i = COREWAR_EXEC_MAGIC;
	size = sizeof(i);
	j = size;
	while (--j >= 0)
		e->data.header.magic[size - j - 1] = (i >> (8 * j)) & 0xff;
}

void					put_size(t_env *e, int end_pos)
{
	if (e->i < end_pos)
		e->i = end_pos;
	e->data.header.prog_size[0] = (e->i & 0xff000000) >> 24;
	e->data.header.prog_size[1] = (e->i & 0xff0000) >> 16;
	e->data.header.prog_size[2] = (e->i & 0xff00) >> 8;
	e->data.header.prog_size[3] = e->i & 0xff;
}

int						main(int c, char **v)
{
	int			fd;
	int			ret;
	int			end_pos;
	t_env		env;

	fd = 0;
	ft_bzero(&env, sizeof(t_env));
	put_magic(&env);
	e_error(c > 2, E2BIG);
	if (c == 2 && (fd = open(v[1], O_RDONLY)) < 0)
		e_error(1, 0);
	env.path = (fd ? v[1] : "stdin");
	while ((ret = get_next_line(fd, &env.line)) > 0 && (env.y++ || 1))
	{
		if (!start_with(env.line, COMMENT_CHAR))
			env.true_l += parse(&env);
		ft_strdel(&env.line);
	}
	e_error(ret < 0, 0);
	close(fd);
	end_pos = env.i;
	put_label_pos(&env);
	put_size(&env, end_pos);
	put_output(&env);
	free_struct(&env);
	return (0);
}
