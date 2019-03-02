/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:31:46 by agissing          #+#    #+#             */
/*   Updated: 2019/03/02 20:06:27 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bufizer.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
	s = str;
}

static void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

void		print_all(int fd)
{
	t_bfz	*buf;
	t_bfz	*tmp;

	buf = g_buffer;
	while (buf)
	{
		write(fd, buf->buffer, buf->i);
		tmp = buf;
		buf = buf->next;
		free(tmp);
	}
}

void		new_buff(void)
{
	if (!g_buffer)
	{
		if (!(g_buffer = (t_bfz *)ft_memalloc(sizeof(t_bfz))))
			exit(1);
		g_current = g_buffer;
		return ;
	}
	if (!(g_current->next = (t_bfz *)ft_memalloc(sizeof(t_bfz))))
		exit(1);
	g_current = g_current->next;
}
