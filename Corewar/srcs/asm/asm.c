/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:12:00 by trlevequ          #+#    #+#             */
/*   Updated: 2019/03/05 19:35:25 by agissing         ###   ########.fr       */
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

static char				*get_label_name(char *str)
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

static inline int		check_params(char param, unsigned char enc)
{
	unsigned char	val;

	val = 0;
	(param == DIRECT_CHAR) ? val |= T_DIR : 0;
	(param == LABEL_CHAR) ? val |= T_IND : 0;
	(param == 'r') ? val |= T_REG : 0;

	if (val & enc)
		exit(1);
	return (1);
}

static int				get_param(char *str, int index)
{
	int		ok;
	int		count;
	int		i;
	int		j;

	i = -1;
	ok = -1;
	count = 0;
	while (str[++i] || ok >= 0)
	{
		if (str[i] == '#')
			return (1);
		else if (ok == -1 && check_params(str[i], g_op_tab[index].encodage[count]))
			ok = i;
		else if (ok >= 0 && (str[i] == SEPARATOR_CHAR || is_space(str[i]) || str[i] == '\n' || !str[i]))
		{
			ft_putstr(COLOR_GREEN);
			ft_putstr(g_op_tab[index].name);
			ft_putstr(COLOR_END);
			ft_putstr(" :: new param :: '");
			j = ok;
			while (j < i)
				write(1, &str[j++], 1);
			ft_putendl("'");
			ok = -1;
			count++;
			if (!str[i])
				return (1);
		}
	}
	return (!!count);
}

static int				get_index(char *str)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].name)
		if (is_space(str[g_op_tab[i].name_size]) &&
			!ft_strncmp(g_op_tab[i].name, str, g_op_tab[i].name_size))
			return (get_param(str + g_op_tab[i].name_size, i)); // need to check params
	return (-1);
}

static void				extract_quotes(char *str, t_header *h, int name)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '"') // check if there is no #
		i++;
	i++;
	while (str[i] && str[i] != '"')
		if (name)
			h->prog_name[j++] = str[i++];
		else
			h->comment[j++] = str[i++];
	if (!str[i])
		exit(1); //ERROR
}

// fonction qui donne la valeur de check pour comparer

// fonction qui separe tout les args

static int				parse(char *str, int count, t_header *h)
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
		extract_quotes(str, h, count == 0);
	else
		while (str[++i])
		{
			if (str[i] == COMMENT_CHAR)
				return (1);
			if (str[i] == LABEL_CHAR && str[i - 1] != DIRECT_CHAR)
			{
				printf("%sThere is a label :: %s%s\n", COLOR_RED, (tmp = get_label_name(str)), COLOR_END);
				free(tmp);
			}
			else if ((id = get_index(str + i)) >= 0)
				return (1);
		}
	return (1);
}

int						main(int c, char **v)
{
	int			fd;
	int			ret;
	int			n_line;
	char		*line;
	char		champ[CHAMP_MAX_SIZE];
	t_header	header;

	fd = 0;
	n_line = 0;
	header.magic = COREWAR_EXEC_MAGIC;
	e_error(c > 2, E2BIG);								// if too many args
	bzero(champ, CHAMP_MAX_SIZE);						// bzero the buffer
	if (c == 2 && (fd = open(v[1], O_RDONLY)) < 0)		// if there is an arg open the filename
		e_error(1, 0);									// if open fail
	while ((ret = get_next_line(fd, &line)) > 0)		// read all lines
	{		
		if (!start_with(line, COMMENT_CHAR))			// test if line is a comment
			n_line += parse(line, n_line, &header);		// parse the line
		free(line);										// free the line
	}
	e_error(ret < 0, 0);								// if read fail
	write(1, (char *)&header, sizeof(header));
	return (0);
}

