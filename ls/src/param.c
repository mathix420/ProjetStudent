/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:13:31 by agissing          #+#    #+#             */
/*   Updated: 2019/01/18 16:17:29 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param	*ft_create_param(char *name)
{
	t_param		*lst;

	if ((!(lst = (t_param *)malloc(sizeof(t_param)))))
		return (NULL);
	lst->next = NULL;
	lst->name = ft_strdup(name);
	if (!(lst->child = (t_lst **)malloc(sizeof(t_lst *))))
		return (NULL);
	return (lst);
}

void	ft_param_push_back(t_param **lst, char *name)
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_param_push_back(&((*lst)->next), name);
		else
			(*lst)->next = ft_create_param(name);
	}
	else
		(*lst) = ft_create_param(name);
}
