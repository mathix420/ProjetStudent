/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:21:24 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/20 20:32:29 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_childs(t_param *params, char opt)
{
	DIR				*d;
	struct dirent	*dir;

	while (params)
	{
		if ((d = opendir(params->name)))
		{
			while ((dir = readdir(d)))
				if (opt & OPT_A || dir->d_name[0] != '.')
					ft_lst_push_back(params->child, dir->d_name, params->name);
			closedir(d);
		}
		params = params->next;
	}
}

void	simple_print(t_lst *lst, char opt)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		ft_putstr(ft_title(lst->name));
		if (lst->next)
			ft_putchar('\t');
		else
			ft_putchar('\n');
		lst = lst->next;
	}
}

void	list_print(t_lst *lst, char opt)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		printf("%s ", write_perms(lst->stat.st_mode));
		printf("%3d", lst->stat.st_nlink);
		printf("%9s ", lst->pswd->pw_name);
		printf("%11s ", lst->grp->gr_name);
		printf("%6lld ", lst->stat.st_size);
		printf("%s ", cut_time_opt(ctime(&lst->stat.st_ctime)));
		printf("%s", ft_title(lst->name));
		printf("\n");
		lst = lst->next;
	}
}
