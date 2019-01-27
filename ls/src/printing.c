/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:57:16 by agissing          #+#    #+#             */
/*   Updated: 2019/01/26 14:09:39 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_g(t_lst *lst, t_buf *i)
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
	ft_addstr(i, ft_title(lst->name, lst->t));
	ft_addstr(i, "\033[0m");
}

void	simple_print(t_lst *lst, t_buf *i, char opt)
{
	ft_sort(&lst, opt);
	if (opt & OPT_LR)
		reverse_lst(&lst);
	while (lst)
	{
		if (opt & OPT_G)
			print_g(lst, i);
		else
			ft_addstr(i, ft_title(lst->name, lst->t));
		if (lst->next)
			ft_addstr(i, "  ");
		else
			ft_addchar(i, '\n');
		lst = lst->next;
	}
}

void	list_print(t_lst *lst, char op, t_buf *i)
{
	ft_sort(&lst, op);
	if (op & OPT_LR)
		reverse_lst(&lst);
	total(i, lst);
	while (lst)
	{
		leading(11, write_perms(lst->stat.st_mode), i);
		leading_nbr(2, lst->stat.st_nlink, i);
		leading(10, lst->pswd->pw_name, i);
		leading(12, lst->grp->gr_name, i);
		leading_nbr(5, lst->stat.st_size, i);
		leading(13, cut_time_opt(ctime(&lst->stat.st_ctime)), i);
		op & OPT_G ? print_g(lst, i)
			: ft_addstr(i, ft_title(lst->name, lst->t));
		S_ISLNK(lst->stat.st_mode) ? ft_addtwostr(i, " -> ",
					link_pointer(lst->name)) : 0;
		ft_addchar(i, '\n');
		lst = lst->next;
	}
}

char	*write_perms(int perm)
{
	char	*str;

	if (!(str = ft_strnew(10)))
		return (NULL);
	str[0] = '-';
	S_ISCHR(perm) ? str[0] = 'c' : 0;
	S_ISBLK(perm) ? str[0] = 'b' : 0;
	S_ISDIR(perm) ? str[0] = 'd' : 0;
	S_ISLNK(perm) ? str[0] = 'l' : 0;
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
