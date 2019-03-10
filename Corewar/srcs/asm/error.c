/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:21:50 by agissing          #+#    #+#             */
/*   Updated: 2019/03/10 17:18:18 by agissing         ###   ########.fr       */
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

void					p_error(t_env *e, int code)
{
	char	*err[8];

	err[0] = "\e[1m%s:%d:%d: asm:%s No name or comment%s: first commands must \
be %s and %s\n";
	err[1] = "\e[1m%s:%d:%d: asm:%s Bad parameter%s\n";
	err[2] = "\e[1m%s:%d:%d: asm:%s Bad label name%s\n";
	err[3] = "\e[1m%s:%d:%d: asm:%s Bad number of parameters%s\n";
	err[4] = "\e[1m%s:%d:%d: asm:%s Unknown command%s\n";
	err[5] = "\e[1m%s:%d:%d: asm:%s missing terminating `\"`%s\n";
	err[6] = "\e[1m%s:%d:%d: asm:%s Bad syntaxe%s\n";
	err[7] = "\e[1m%s:%d:%d: asm:%s Label name already exist%s\n";
	printf(err[code - 1], e->path, e->y, e->x, COLOR_RED, COLOR_END,
		NAME_CMD_STRING, COMMENT_CMD_STRING);
	ft_putendl(e->line);
	if (e->x > -1)
		printf("%s%*s%s\n", COLOR_GREEN, e->x + 1, "^", COLOR_END);
	if (e->line)
		ft_strdel(&e->line);
	free_struct(e);
	exit(1);
}

void					custom_error(t_env *e, char *str, int code)
{
	(void)code;
	printf("\e[1m%s: asm:%s Bad label name%s\n",
		e->path, COLOR_RED, COLOR_END);
	ft_putendl(str);
	free_struct(e);
	exit(1);
}
