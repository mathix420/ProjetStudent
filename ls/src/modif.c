/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:47:31 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/17 20:26:55 by kemartin         ###   ########.fr       */
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
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lst	*tmp3;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp1 = (*lst);
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	tmp1->next = NULL;
	tmp2->next = tmp1;
	while (tmp3)
	{
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
		tmp2->next = tmp1;
	}
	lst = &tmp2;
}

char	*write_perms(int perm)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * 11)))
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
	str[10] = '\0';
	return (str);
}

char	*ft_title(char *title)
{
	int		i;

	while (ft_strchr(title, '/'))
		title = ft_strchr(title, '/') + 1;
	i = ft_strlen(title);
	while (i && title[i] == '.' ? title[i] = '\0' : 1)
		i--;
	return (title);
}
