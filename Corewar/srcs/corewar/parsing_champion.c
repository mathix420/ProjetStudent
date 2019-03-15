/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:53:48 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/15 14:52:20 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"

void	parsing_len_champ(int fd, t_champion *champion, char *file_name)
{
	unsigned char	*name;

	if ((name = (unsigned char*)ft_strnew(sizeof(int))) == NULL)
		ft_exit_parsing(1, file_name);
	if ((read(fd, name, sizeof(int))) != sizeof(int))
		ft_exit_parsing(0, file_name);
	champion->size_instructions = convert_to_int(name);
	free(name);
}

void	parsing_comment(int fd, t_champion *champion, char *file_name)
{
	char	*name;

	if ((name = ft_strnew(COMMENT_LENGTH)) == NULL)
		ft_exit_parsing(1, file_name);
	if ((read(fd, name, COMMENT_LENGTH)) != COMMENT_LENGTH)
		ft_exit_parsing(0, file_name);
	champion->comment = ft_strdup(name);
	free(name);
	if ((name = ft_strnew(4)) == NULL)
		ft_exit_parsing(1, file_name);
	if ((read(fd, name, 4)) != 4)
		ft_exit_parsing(0, file_name);
	free(name);
}

void	parsing_instructions(int fd, t_champion *champion, char *file_name)
{
	char	*name;
	int		size;
	int		res;

	if ((name = ft_strnew(CHAMP_MAX_SIZE)) == NULL)
		ft_exit_parsing(1, file_name);
	size = 0;
	while ((res = read(fd, name, CHAMP_MAX_SIZE)) != 0)
	{
		if (res == -1)
			ft_exit_parsing(0, file_name);
		ft_bzero(name, CHAMP_MAX_SIZE + 1);
		size += res;
	}
	if (size != champion->size_instructions)
		ft_exit_parsing(4, file_name);
	else if (size > CHAMP_MAX_SIZE)
		ft_exit_size(6, file_name, size);
	champion->size = size;
	free(name);
}

void	parsing_champ(char *file_name, t_champion *champion)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_exit_parsing(2, file_name);
	parsing_size_file(file_name);
	parsing_exec_magic(fd, file_name);
	parsing_name(fd, champion, file_name);
	parsing_len_champ(fd, champion, file_name);
	parsing_comment(fd, champion, file_name);
	parsing_instructions(fd, champion, file_name);
	close(fd);
}
