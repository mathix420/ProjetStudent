/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:21:50 by agissing          #+#    #+#             */
/*   Updated: 2019/03/12 20:08:19 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void					e_error(int cond, int error_code)
{
	if (!cond)
		return ;
	(error_code) ? errno = error_code : 0;
	perror("asm");
	exit(1);
}

static inline void		put_pointer(t_env *e)
{
	while (e->x-- > 0)
		write(1, " ", 1);
	ft_putstr(COLOR_GREEN);
	write(1, "^", 1);
	ft_putendl(COLOR_END);
}

static inline void		put_message(t_mess message)
{
	ft_putstr(e->path);
	ft_putstr(e->path);
}

void					p_error(t_env *e, int code)
{
	t_mess	err[10];

	err[0] = {e->path, ": asm:", " No name or comment", e->x, e->y, 1};
	err[0] = "\e[1m%s:%d:%d: asm:%s No name or comment%s: first commands must \
be %s and %s\n";
	err[1] = {e->path, ": asm:", " Bad parameter", e->x, e->y, 0};
	err[2] = {e->path, ": asm:", " Bad label name", e->x, e->y, 0};
	err[3] = {e->path, ": asm:", " Bad number of parameters", e->x, e->y, 0};
	err[4] = {e->path, ": asm:", " Unknown command", e->x, e->y, 0};
	err[5] = {e->path, ": asm:", " missing terminating `\"`", e->x, e->y, 0};
	err[6] = {e->path, ": asm:", " Bad syntaxe", e->x, e->y, 0};
	err[7] = {e->path, ": asm:", " Label name already taken", e->x, e->y, 0};
	err[8] = {e->path, ": asm:", " Argument out of bounds", e->x, e->y, 0};
	err[9] = {e->path, ": asm:", " Champion too big", e->x, e->y, 0};
	put_message(message);
//	printf(err[code - 1], e->path, e->y, e->x, COLOR_RED, COLOR_END,
//		NAME_CMD_STRING, COMMENT_CMD_STRING);
	put_string_tab(e, e->line);
	put_pointer(e);
	if (e->line)
		ft_strdel(&e->line);
	free_struct(e);
	exit(1);
}

void					custom_error(t_env *e, char *str, int code)
{
	(void)code;
	ft_putstr(FONT_BOLD);
	ft_putstr(e->path);
	ft_putstr(": asm:");
	ft_putstr(COLOR_RED);
	ft_putstr(" No such label: ");
	ft_putstr(COLOR_END);
	ft_putstr(FONT_BOLD);
	ft_putchar('\'');
	ft_putstr(str);
	ft_putendl("'");
	free_struct(e);
	exit(1);
}
