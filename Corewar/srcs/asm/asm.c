/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:12:00 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/04 21:21:47 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void				e_error(int cond, int error_code)
{
	if (!cond)
		return ;
	(error_code) ? errno = error_code : 0;
	perror("asm");
	exit(1);
}

static void						p_error(int x, char *line, int code)
{
	if (code == NO_NAME_OR_COMMENT)
		printf("asm:%s No name or comment%s: first commands must \
be .name and .comment\n", COLOR_RED, COLOR_END);
	printf("\t%s\n", line);
	printf("\t%s%*s%s\n", COLOR_GREEN, x, "~~~~", COLOR_END);
	exit(1);
}

static inline int				is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f');
}

static int				start_with(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!is_space(str[i]))
			return (c == str[i]);
	return (0);
}

static int				

static int				parse(char *str, int count)
{
	int		i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i])
	{
		if (count < 2 && str[i] != '.')
			p_error(i, str + i, NO_NAME_OR_COMMENT);
		else if (count < 2)
			printf(count == 0 ? "NAME :: %s\n" : "COMMENT :: %s\n", str);
		else
			printf("IN PARSE :: '''%s'''\n", str);
	}
	return (1);
}

int						main(int c, char **v)
{
	int		fd;
	int		ret;
	int		n_line;
	char	*line;
//	char	str[5000];

	fd = 0;
	n_line = 0;
	e_error(c > 2, E2BIG);
	if (c == 2 && (fd = open(v[1], O_RDONLY)) < 0)
		e_error(1, 0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{		
		if (!start_with(line, COMMENT_CHAR))
			n_line += parse(line, n_line);
		free(line);
	}
	e_error(ret < 0, 0);
	return (0);
}
