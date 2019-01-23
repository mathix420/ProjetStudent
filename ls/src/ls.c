/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:21:24 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/23 19:06:14 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	files_err(char *name)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": No such file or directory", 2);
}	

void	get_childs(t_param *p, char opt)
{
	DIR				*d;
	struct dirent	*dir;

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
			p->ok = 0;
			files_err(p->name);
		}
		p = p->next;
	}
}

void	print_G(t_lst *lst, t_buf *i)
{
	if (S_ISDIR(lst->stat.st_mode))
		ft_addstr(i, "\033[1;36m");
	else if (S_ISLNK(lst->stat.st_mode))
		ft_addstr(i, "\033[0;35m");
	else if (lst->stat.st_mode & S_IXUSR)
		ft_addstr(i, "\033[0;31m");
	else if (S_ISCHR(lst->stat.st_mode))
		ft_addstr(i, "\033[43m\033[34m");
	else if (S_ISBLK(lst->stat.st_mode))
		ft_addstr(i, "\033[46m\033[34m");
	ft_addstr(i, ft_title(lst->name));
	ft_addstr(i, "\033[0m");
}

void	simple_print(t_lst *lst, t_buf *i, char opt)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		opt & OPT_G ? print_G(lst, i)
			: ft_addstr(i, ft_title(lst->name));
		if (lst->next)
			ft_addstr(i, "  ");
		else
			ft_addchar(i, '\n');
		lst = lst->next;
	}
}

void	leading(int size, char *str, t_buf *i)
{
	int		j;

	j = 0;
	while (str[j++])
		size--;
	ft_addstr(i, str);
	while (size-- > 0)
		ft_addchar(i, ' ');
}

void	leading_nbr(int size, int nbr, t_buf *i)
{
	unsigned	cpy;

	cpy = nbr < 0 ? -nbr : nbr;
	while ((cpy /= 10) > 0)
		size--;
	size--;
	while (size-- >= 0)
		ft_addchar(i, ' ');
	ft_addnbr(i, nbr);
	ft_addchar(i, ' ');
}

void	list_print(t_lst *lst, char opt, t_buf *i)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		leading(11, write_perms(lst->stat.st_mode), i);
		leading_nbr(2, lst->stat.st_nlink, i);
		leading(10, lst->pswd->pw_name, i);
		leading(12, lst->grp->gr_name, i);
		leading_nbr(3, lst->stat.st_size, i);
		leading(13, cut_time_opt(ctime(&lst->stat.st_ctime)), i);
		opt & OPT_G ? print_G(lst, i)
			: ft_addstr(i, ft_title(lst->name));
		ft_addchar(i, '\n');
		lst = lst->next;
	}
}
