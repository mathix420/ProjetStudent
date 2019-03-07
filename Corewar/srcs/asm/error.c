/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:21:50 by agissing          #+#    #+#             */
/*   Updated: 2019/03/07 20:39:46 by agissing         ###   ########.fr       */
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
	char	*err[7];

	err[0] = "asm:%s No name or comment%s: first commands must be %s and %s\n";
	err[1] = "asm:%s Bad parameter%s\n";
	err[2] = "asm:%s Bad label name%s\n";
	err[3] = "asm:%s Bad number of parameters%s\n";
	err[4] = "asm:%s Unknown command%s\n";
	err[5] = "asm:%s missing terminating `\"`%s\n";
	err[6] = "asm:%s Bad syntaxe%s\n";
	printf(err[code - 1], COLOR_RED, COLOR_END,
		NAME_CMD_STRING, COMMENT_CMD_STRING);
	printf("%s\n", e->line);
	printf("x=%d y=%d\n", e->x, e->y);
	if (e->x > -1)
		printf("%s%*s%s\n", COLOR_GREEN, e->x + 1, "^", COLOR_END);
	exit(1);
}
