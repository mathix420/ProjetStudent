/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:53:20 by jnoe              #+#    #+#             */
/*   Updated: 2019/01/25 17:10:03 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_realloc(char *str, char **line, int len)
{
	char	*new_line;
	int		i;
	int		j;
	int		len_line;

	len_line = 0;
	while ((*line)[len_line] != '\0')
		len_line++;
	if ((new_line = (char *)malloc(len + len_line + 1)) == NULL)
		return (-1);
	i = -1;
	while ((*line)[++i] != '\0')
		new_line[i] = (*line)[i];
	j = -1;
	while (++j < len)
		new_line[i + j] = str[j];
	new_line[i + j] = '\0';
	free(*line);
	*line = new_line;
	return (1);
}

int		check_endline(const int fd, char **str, char **line)
{
	int i;
	int n;

	if (*str == NULL || (*str)[0] == 0)
	{
		free(*str);
		if ((*str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
			return (-1);
		if ((n = read(fd, *str, BUFF_SIZE)) == -1)
			return (-1);
		(*str)[n] = '\0';
		if (n == 0 && *line[0] == '\0')
			return (0);
		if (n == 0 && *line[0] != '\0')
			return (1);
	}
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if (ft_realloc(*str, line, i) == -1)
		return (-1);
	if ((*str)[i] == '\n')
		return (ft_strpart(str, i + 1));
	ft_strpart(str, i);
	return (check_endline(fd, str, line));
}

int		ft_strpart(char **str, int i)
{
	char	*newstr;
	int		j;
	int		len;

	len = 0;
	while ((*str)[len] != '\0')
		len++;
	if ((newstr = (char *)malloc(sizeof(char) * (len - i + 1))) == NULL)
		return (-1);
	j = 0;
	while ((*str)[i] != '\0')
	{
		newstr[j] = (*str)[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	free(*str);
	*str = newstr;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			res;

	if (fd < 0)
		return (-1);
	if (line == NULL)
		return (-1);
	*line = NULL;
	free(*line);
	if ((*line = (char *)malloc(1)) == NULL)
		return (-1);
	*line[0] = '\0';
	res = (check_endline(fd, &str, line));
	if (res == 0 || res == -1)
		free(str);
	return (res);
}
