/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_childs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:56:16 by agissing          #+#    #+#             */
/*   Updated: 2019/01/26 14:05:57 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_childs(t_param *p, char opt)
{
	DIR				*d;
	struct dirent	*dir;
	struct stat		buffer;

	while (p)
	{
		if ((d = opendir(p->name)))
		{
			while ((dir = readdir(d)))
				if (opt & OPT_A || dir->d_name[0] != '.')
					ft_lst_push_back(p->child, dir->d_name, p->name);
			closedir(d);
		}
		else
		{
			if (lstat(p->name, &buffer) < 0 && !(p->ok = 0))
				files_err(p->name);
			else
				ft_lst_push_back(p->child, p->name, "");
		}
		p = p->next;
	}
}
