/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:47:57 by agissing          #+#    #+#             */
/*   Updated: 2019/01/25 14:17:36 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		total(t_buf *i, t_lst *lst)
{
	int		tot;

	tot = 0;
	while (lst)
	{
		tot += lst->stat.st_blocks;
		lst = lst->next;
	}
	ft_addstr(i, "total ");
	ft_addnbr(i, tot);
	ft_addchar(i, '\n');
}
