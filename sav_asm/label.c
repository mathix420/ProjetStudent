/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:00:13 by agissing          #+#    #+#             */
/*   Updated: 2019/03/10 20:48:09 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int		is_end_param(char c)
{
	return (!c || c == SEPARATOR_CHAR || c == COMMENT_CHAR
			|| c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

void					add_new_label(t_env *e, char *name)
{
	t_label		*new;
	t_label		*tmp;

	if (label_exist(e, name))
	{
		ft_strdel(&name);
		p_error(e, LABEL_NAME_EXIST);
	}
	e_error(!(new = ft_memalloc(sizeof(t_label))), ENOMEM);
	new->name = name;
	new->pos = &e->data.champ[e->i];
	new->next = NULL;
	if (!e->labels)
		e->labels = new;
	else
	{
		tmp = e->labels;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_label					*label_exist(t_env *e, char *name)
{
	t_label		*tmp;

	tmp = e->labels;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int						label_to_put(t_env *e, int nb_oct)
{
	t_todo	*new;
	t_todo	*tmp;
	int		count;

	count = 0;
	tmp = e->to_put;
	while (!is_end_param(e->line[e->x + count]))
		count++;
	e_error(!(new = ft_memalloc(sizeof(t_todo))), ENOMEM);
	e_error(!(new->name = ft_strnew(count)), ENOMEM);
	ft_strncpy(new->name, e->line + e->x, count);
	new->op_pos = e->op_char;
	new->nb_oct = nb_oct;
	new->cursor = e->i;
	(!e->to_put) ? e->to_put = new : 0;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp ? tmp->next = new : 0;
	return ('@');
}

void					put_label_pos(t_env *e)
{
	t_todo		*tmp;
	t_label		*label;
	int			val;

	while (e->to_put)
	{
		label = e->labels;
		while (label && ft_strcmp(label->name, e->to_put->name))
			label = label->next;
		(!label) ? custom_error(e, e->to_put->name, BAD_LABEL_NAME) : 0;
		e->i = e->to_put->cursor;
		val = (e->to_put->nb_oct == 4) ? (int)(label->pos - e->to_put->op_pos)
			: (short)(label->pos - e->to_put->op_pos);
		if (e->to_put->nb_oct == 4)
		{
			add_to_champ(e, (val & 0xff000000) >> 24);
			add_to_champ(e, (val & 0xff0000) >> 16);
		}
		add_to_champ(e, (val & 0xff00) >> 8);
		add_to_champ(e, val & 0xff);
		free(e->to_put->name);
		tmp = e->to_put;
		e->to_put = e->to_put->next;
		free(tmp);
	}
}
