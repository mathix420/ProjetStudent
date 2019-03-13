/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:21:50 by agissing          #+#    #+#             */
/*   Updated: 2019/03/13 16:55:05 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <sys/ioctl.h>

void							e_error(int cond, int error_code)
{
	if (!cond)
		return ;
	(error_code) ? errno = error_code : 0;
	perror("asm");
	exit(1);
}

static inline void				put_pointer(t_env *e)
{
	struct winsize	ws;
	int				fd;

	e_error((fd = open("/dev/tty", O_RDWR)) < 0, 0);
	e_error(ioctl(fd, TIOCGWINSZ, &ws) < 0, 0);
	if (ws.ws_col > 0)
		e->x %= ws.ws_col;
	put_blank(e);
	ft_putstr(COLOR_GREEN);
	write(1, "^", 1);
	ft_putendl(COLOR_END);
}

static inline void				put_message(t_mess message)
{
	ft_putstr(FONT_BOLD);
	ft_putstr(message.path);
	ft_putchar(':');
	ft_putnbr(message.x);
	ft_putchar(':');
	ft_putnbr(message.y);
	ft_putstr(message.name);
	ft_putstr(COLOR_END);
	ft_putstr(COLOR_RED);
	ft_putstr(message.err);
	ft_putstr(COLOR_END);
	if (message.cmd)
	{
		ft_putstr(": first commands must be ");
		ft_putstr(NAME_CMD_STRING);
		ft_putstr(" or ");
		ft_putstr(COMMENT_CMD_STRING);
	}
	ft_putchar('\n');
}

void							p_error(t_env *e, int code)
{
	t_mess		*err;

	err = (t_mess[10]){
		{e->path, ": asm:", " No name or comment", e->x, e->y, 1},
		{e->path, ": asm:", " Bad parameter", e->x, e->y, 0},
		{e->path, ": asm:", " Bad label name", e->x, e->y, 0},
		{e->path, ": asm:", " Bad number of parameters", e->x, e->y, 0},
		{e->path, ": asm:", " Unknown command", e->x, e->y, 0},
		{e->path, ": asm:", " missing terminating `\"`", e->x, e->y, 0},
		{e->path, ": asm:", " Bad syntaxe", e->x, e->y, 0},
		{e->path, ": asm:", " Label name already taken", e->x, e->y, 0},
		{e->path, ": asm:", " Argument out of bounds", e->x, e->y, 0},
		{e->path, ": asm:", " Champion too big", e->x, e->y, 0}
	};
	put_message(err[code - 1]);
	put_string_tab(e, e->line);
	if (code == UNKNOWN_COMMAND)
		trace(e);
	else
		put_pointer(e);
	if (e->line)
		ft_strdel(&e->line);
	free_struct(e);
	exit(1);
}

void							custom_error(t_env *e, char *str, int code)
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
	ft_putchar('\'');
	ft_putendl(COLOR_END);
	free_struct(e);
	exit(1);
}
