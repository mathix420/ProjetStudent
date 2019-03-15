/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:57:55 by jnoe              #+#    #+#             */
/*   Updated: 2019/03/14 14:35:20 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"

void	parsing_size_file(char *file_name)
{
	int		res;
	int		fd;
	char	*name;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_exit_parsing(2, file_name);
	if ((name = ft_strnew(sizeof(t_header))) == NULL)
		ft_exit_parsing(1, file_name);
	res = read(fd, name, sizeof(t_header));
	if (res == -1)
		ft_exit_parsing(0, file_name);
	if (res != sizeof(t_header))
		ft_exit_size(5, file_name, 0);
	free(name);
	close(fd);
}

void	parsing_exec_magic(int fd, char *file_name)
{
	unsigned char	*name;
	int				exec_magic;

	if ((name = (unsigned char*)ft_strnew(sizeof(int))) == NULL)
		ft_exit_parsing(1, file_name);
	if ((read(fd, name, sizeof(int))) != sizeof(int))
		ft_exit_parsing(0, file_name);
	exec_magic = convert_to_int(name);
	if (exec_magic != COREWAR_EXEC_MAGIC)
		ft_exit_parsing(3, file_name);
	free(name);
}

void	parsing_name(int fd, t_champion *champion, char *file_name)
{
	char	*name;

	if ((name = ft_strnew(PROG_NAME_LENGTH)) == NULL)
		ft_exit_parsing(1, file_name);
	if ((read(fd, name, PROG_NAME_LENGTH)) != PROG_NAME_LENGTH)
		ft_exit_parsing(0, file_name);
	champion->name = ft_strdup((const char*)name);
	free(name);
	if ((name = ft_strnew(4)) == NULL)
		ft_exit_parsing(1, file_name);
	if ((read(fd, name, 4)) != 4)
		ft_exit_parsing(0, file_name);
	free(name);
}
