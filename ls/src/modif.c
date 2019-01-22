/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:47:31 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/22 15:55:31 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*cut_time_opt(char *str)
{
	int		i;
	int		j;
	char	*date;

	if (!(date = (char *)malloc(sizeof(char) * 17)))
		return (NULL);
	i = 4;
	j = 0;
	while (i < 16 && str[i])
		date[j++] = str[i++];
	date[j] = '\0';
	return (date);
}

void	reverse_lst(t_lst **lst)
{
	t_lst	*current;
	t_lst	*previous;
	t_lst	*next;

	if (!(*lst) || !(*lst)->next)
		return ;
	current = *lst;
	previous = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*lst = previous;
}

void	reverse_param(t_param **lst)
{
	t_param	*current;
	t_param	*previous;
	t_param	*next;

	if (!(*lst) || !(*lst)->next)
		return ;
	current = *lst;
	previous = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*lst = previous;
}

char	*write_perms(int perm)
{
	char	*str;

	if (!(str = ft_strnew(10)))
		return (NULL);
	str[0] = (S_ISDIR(perm) ? 'd' : '-');
	str[1] = ((perm & S_IRUSR) ? 'r' : '-');
	str[2] = ((perm & S_IWUSR) ? 'w' : '-');
	str[3] = ((perm & S_IXUSR) ? 'x' : '-');
	str[4] = ((perm & S_IRGRP) ? 'r' : '-');
	str[5] = ((perm & S_IWGRP) ? 'w' : '-');
	str[6] = ((perm & S_IXGRP) ? 'x' : '-');
	str[7] = ((perm & S_IROTH) ? 'r' : '-');
	str[8] = ((perm & S_IWOTH) ? 'w' : '-');
	str[9] = ((perm & S_IXOTH) ? 'x' : '-');
	return (str);
}

char	*ft_title(char *title)
{
	int		i;

	while (ft_strchr(title, '/'))
		title = ft_strchr(title, '/') + 1;
	i = ft_strlen(title);
	return (title);
}
