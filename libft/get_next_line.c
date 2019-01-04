/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:52:34 by agissing          #+#    #+#             */
/*   Updated: 2019/01/04 14:17:46 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file			*ft_newfile(int fd)
{
	t_file		*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->next = NULL;
	file->fd = fd;
	file->sav = NULL;
	return (file);
}

t_file			*ft_gocfile(t_file *file, int fd)
{
	if (file)
	{
		if (file->fd == fd)
			return (file);
		else if (file->next)
			return (ft_gocfile(file->next, fd));
		file->next = ft_newfile(fd);
		return (file->next);
	}
	file = ft_newfile(fd);
	return (file);
}

int				ft_delelem(t_file **file, int fd, int ret)
{
	t_file		*last;
	t_file		*tofree;

	last = *file;
	while (last->fd != fd && last->next && last->next->fd != fd)
		last = last->next;
	tofree = last->fd == fd ? last : last->next;
	if (last->fd == fd)
		*file = tofree->next;
	else
		last->next = tofree->next;
	ft_strdel(&(tofree->sav));
	free(tofree);
	return (ret);
}

int				ft_treat(char **sav, char **line)
{
	char	*tmp;
	int		l_line;

	l_line = 0;
	while ((*sav)[l_line] && (*sav)[l_line] != '\n')
		l_line++;
	if (((*sav)[l_line]) == '\n')
	{
		*line = ft_strsub(*sav, 0, l_line);
		tmp = *sav;
		*sav = ft_strdup(&(*sav)[l_line + 1]);
		free(tmp);
		!(*sav)[0] ? ft_strdel(sav) : 0;
	}
	else if (!((*sav)[l_line]))
	{
		*line = ft_strdup(*sav);
		ft_strdel(sav);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file = NULL;
	t_file			*current;
	char			*tmp;
	char			*buffer;
	int				r;

	if (fd < 0 || !line || (!file && !(file = ft_newfile(fd))))
		return (-1);
	current = ft_gocfile(file, fd);
	if (!current || (!(current->sav) && !(current->sav = ft_strnew(0))) ||
		!(buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (!(r = 0) && !ft_strchr(current->sav, 10) && !ft_strchr(buffer, 10)
		&& (r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = 0;
		tmp = current->sav;
		current->sav = ft_strjoin(current->sav, buffer);
		free(tmp);
	}
	free(buffer);
	if (r < 0 || (r == 0 && (!(current->sav) || !(current->sav)[0])))
		return (ft_delelem(&file, fd, r < 0 ? -1 : 0));
	return (ft_treat(&(current->sav), line));
}
