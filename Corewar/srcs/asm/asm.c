/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:12:00 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/05 14:52:40 by agissing         ###   ########.fr       */
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
be %s and %s\n", COLOR_RED, COLOR_END, NAME_CMD_STRING, COMMENT_CMD_STRING);
	printf("\t`%s`\n", line);
	printf("\t %s%*s%s\n", COLOR_GREEN, x, "^", COLOR_END);
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

static char				*get_name(char *str)
{
	char	*out;
	int		i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
		i++;
	if (!(out = ft_strnew(i)))
		return (NULL);
	return (ft_strncpy(out, str, i)); // need to check LABEL_CHARS
}

static int				get_param(char *str, int index)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		
	}
}

static int				get_index(char *str)
{
	int		i;

	i = -1;
	while (op_tab[++i].name)
		if (is_space(str[op_tab[i].name_size]) &&
			!ft_strncmp(op_tab[i].name, str, op_tab[i].name_size))
			return (get_param(str + op_tab[i].name_size, i)); // need to check params
	return (-1);
}

// fonction qui donne la valeur de check pour comparer

// fonction qui separe tout les args

static int				parse(char *str, int count)
{
	char	*tmp;
	int		i;
	int		id;

	i = -1;
	if ((count == 0 && ft_strncmp(
			str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			|| (count == 1 && ft_strncmp(str, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING))))
		p_error(i, str + i, NO_NAME_OR_COMMENT);
	else if (count < 2)
		printf(count == 0 ? "NAME :: %s\n" : "COMMENT :: %s\n", str);
	while (str[++i])
	{
		if (str[i] == COMMENT_CHAR)
			return (1);
		if (str[i] == LABEL_CHAR && str[i - 1] != DIRECT_CHAR)
		{
			printf("There is a label :: %s\n", (tmp = get_name(str)));
			free(tmp);
		}
		else if ((id = get_index(str + i)) >= 0)
		{
			printf("Get function :: %s\n", op_tab[id].name);
			return (1);
		}
	}
	return (1);
}

int						main(int c, char **v)
{
	int		fd;
	int		ret;
	int		n_line;
	char	*line;
	char	champ[sizeof(t_header) + 682];

	fd = 0;
	n_line = 0;
	e_error(c > 2, E2BIG);								// if too many args
	bzero(champ, sizeof(t_header) + CHAMP_MAX_SIZE);	// bzero the buffer
	if (c == 2 && (fd = open(v[1], O_RDONLY)) < 0)		// if there is an arg open the filename
		e_error(1, 0);									// if open fail
	while ((ret = get_next_line(fd, &line)) > 0)		// read all lines
	{		
		if (!start_with(line, COMMENT_CHAR))			// test if line is a comment
			n_line += parse(line, n_line);				// parse the line
		free(line);										// free the line
	}
	e_error(ret < 0, 0);								// if read fail
	return (0);
}
