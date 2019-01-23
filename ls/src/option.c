/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:09:32 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/23 19:08:55 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	illegal_opt(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-lRart] [file ...]", 2);
	exit(1);
}

void	options(char *str, t_struct *tab)
{
	int			i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			tab->opt |= OPT_L;
		else if (str[i] == 'R')
			tab->opt |= OPT_UR;
		else if (str[i] == 'a')
			tab->opt |= OPT_A;
		else if (str[i] == 'r')
			tab->opt |= OPT_LR;
		else if (str[i] == 't')
			tab->opt |= OPT_T;
		else if (str[i] == 'G')
			tab->opt |= OPT_G;
		else
			illegal_opt(str[i]);
		i++;
	}
}
