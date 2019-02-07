/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:49:26 by kemartin          #+#    #+#             */
/*   Updated: 2019/02/07 18:51:07 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*ft_create_lst(char *name, char *source)
{
	t_lst		*lst;

	if ((!(lst = (t_lst *)malloc(sizeof(t_lst)))))
		return (NULL);
	lst->next = NULL;
	lst->name =	!source[0] ? name : join_path(source, name);
	lst->t = !source[0];
	if (lstat(lst->name, &lst->stat) < 0)
		return (NULL);
	lst->pswd = getpwuid(lst->stat.st_uid);
	lst->grp = getgrgid(lst->stat.st_gid);
	return (lst);
}

void	ft_lst_push_back(t_lst **lst, char *name, char *source)
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_lst_push_back(&((*lst)->next), name, source);
		else
			(*lst)->next = ft_create_lst(name, source);
	}
	else
		(*lst) = ft_create_lst(name, source);
}

void	lstcpy(t_lst *new, t_lst *old)
{
	new->name = old->name;
	if (lstat(new->name, &new->stat) < 0)
		return ;
	new->t = old->t;
	new->pswd = getpwuid(new->stat.st_uid);
	new->grp = getgrgid(new->stat.st_gid);
}

void	ft_sort(t_lst **lst, char opt)
{
	t_lst	*tmp1;
	t_lst	*tmp2;
	t_lst	*tmp3;
	t_lst	*trie;

	tmp1 = (*lst);
	if (!(trie = malloc(sizeof(t_lst))))
		return ;
	while (tmp1 && (tmp3 = tmp1))
	{
		lstcpy(trie, tmp1);
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (opt & OPT_T ? trie->stat.st_ctime < tmp2->stat.st_ctime
				: ft_strcmp(trie->name, tmp2->name) > 0)
				lstcpy(trie, (tmp3 = tmp2));
			tmp2 = tmp2->next;
		}
		lstcpy(tmp3, tmp1);
		lstcpy(tmp1, trie);
		tmp1 = tmp1->next;
	}
	free(trie);
}
