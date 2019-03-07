/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 19:10:41 by agissing          #+#    #+#             */
/*   Updated: 2019/03/07 20:41:50 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int				is_cmd(t_env *e)
{
	char	*name;
	char	*comm;

	e->x = 0;
	name = NAME_CMD_STRING;
	comm = COMMENT_CMD_STRING;
	while (e->line[e->x] && is_space(e->line[e->x]))
		e->x++;
	if (e->true_l == 0 && !ft_strncmp(e->line + e->x, name, ft_strlen(name)))
		return (1);
	else if (e->true_l == 1
			&& !ft_strncmp(e->line + e->x, comm, ft_strlen(comm)))
		return (1);
	else if (e->line[e->x])
		p_error(e, NO_NAME_OR_COMMENT);
	return (0);
}

int						get_name_comment(t_env *e)
{
	int		j;

	j = 0;
	e->x = 0;
	if (!is_cmd(e))
		return (0);
	while (e->line[e->x] && !is_space(e->line[e->x]))
		e->x++;
	while (e->line[e->x] && is_space(e->line[e->x]) && e->line[e->x] != '"')
		e->x++;
	if (e->line[e->x] != '"')
		p_error(e, BAD_SYNTAXE);
	e->x++;
	while (e->line[e->x] && e->line[e->x] != '"')
		if (!e->true_l)
			e->data.header.prog_name[j++] = e->line[e->x++];
		else
			e->data.header.comment[j++] = e->line[e->x++];
	if (e->line[e->x] != '"')
		p_error(e, BAD_QUOTES);
	while (e->line[++e->x])
		if (!is_space(e->line[e->x]))
			p_error(e, BAD_SYNTAXE);
	return (1);
}
