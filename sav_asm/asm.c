/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:12:00 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/10 20:24:38 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char				*get_label_name(t_env *e)
{
	char	*out;
	int		j;

	j = 0;
	e->x = 0;
	while (e->line[e->x] && e->line[e->x] != LABEL_CHAR
				&& is_in_str(e->line[e->x], LABEL_CHARS))
		e->x++;
	if (e->line[e->x] != LABEL_CHAR)
		p_error(e, BAD_LABEL_NAME);
	if (!(out = ft_strnew(e->x)))
		return (NULL);
	return (ft_strncpy(out, e->line, e->x));
}

int						get_param(t_env *e, int index)
{
	int		ok;
	int		count;

	ok = -1;
	count = 0;
	while (e->line[++e->x] || ok >= 0)
	{
		if (ok == -1 && check_params(e, g_op_tab[index].encodage[count], count))
			ok = e->x;
		else if (ok >= 0 && (e->line[e->x] == SEPARATOR_CHAR || !e->line[e->x]
				|| is_space(e->line[e->x]) || e->line[e->x] == COMMENT_CHAR))
		{
			ok = -1;
			count++;
			if (!e->line[e->x] && g_op_tab[index].nb_param == count)
				return (1);
			else if (!e->line[e->x])
				p_error(e, BAD_PARAM_NUMBER);
		}
		else if (ok == -1 && !is_space(e->line[e->x]) && e->line[e->x] != '#'
			&& e->line[e->x] != SEPARATOR_CHAR)
			p_error(e, UNKNOWN_COMMAND);
		if (e->line[e->x] == '#' && g_op_tab[index].nb_param == count)
			return (1);
		else if (e->line[e->x] == '#' || count > g_op_tab[index].nb_param)
			p_error(e, BAD_PARAM_NUMBER);
	}
	if (g_op_tab[index].nb_param != count)
		p_error(e, BAD_PARAM_NUMBER);
	return (1);
}

static int				get_index(t_env *e)
{
	int		i;
	int		tmp;
	int		blank;
	int		max_size;

	i = -1;
	tmp = e->x;
	blank = 0;
	max_size = ft_strlen(e->line);
	while (g_op_tab[++i].name)
	{
		e->x = tmp + g_op_tab[i].name_size;
		if (e->x < max_size && is_space(e->line[e->x])
		&& !ft_strncmp(g_op_tab[i].name, e->line + tmp, g_op_tab[i].name_size))
			return (add_op(e, i));
	}
	e->x = tmp;
	return (-1);
}

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
	while ((ret = get_next_line(fd, &env.line)) > 0)
	{
		env.y++;
		if (!start_with(env.line, COMMENT_CHAR))
			env.true_l += parse(&env);
		ft_strdel(&env.line);
	}
	e_error(ret < 0, 0);
	end_pos = env.i;
	put_label_pos(&env);
	put_size(&env, end_pos);
	write(1, (char *)&env.data, sizeof(t_header) + env.i);
	free_struct(&env);
	return (0);
}
