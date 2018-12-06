/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:08:48 by agissing          #+#    #+#             */
/*   Updated: 2018/11/06 16:32:03 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void		ft_putchar(char c, int out)
{
	write(out, &c, 1);
}

void		ft_putstr(char *str, int out)
{
	while (*str != '\0')
		ft_putchar(*str++, out);
}

int			main(int c, char **v)
{
	int		fd;
	int		rd;
	char	str[10001];

	if (c < 2)
		ft_putstr("File name missing.\n", 2);
	else if (c > 2)
		ft_putstr("Too many arguments.\n", 1);
	else if ((fd = open(v[1], O_RDONLY)))
		if ((rd = read(fd, str, 10000)))
		{
			str[rd] = '\0';
			ft_putstr(str, 1);
		}
	return (0);
}
