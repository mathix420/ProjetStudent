/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:13:31 by agissing          #+#    #+#             */
/*   Updated: 2019/01/22 20:33:46 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_param	*ft_create_param(char *name)
{
	t_param		*lst;

	if ((!(lst = (t_param *)malloc(sizeof(t_param)))))
		return (NULL);
	lst->next = NULL;
	lst->ok = 1;
	lst->name = name != NULL ? name : ".";
	if (!(lst->child = (t_lst **)malloc(sizeof(t_lst *))))
		return (NULL);
	*(lst->child) = NULL;
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

void	ft_param_push_after(t_param *lst, char *name)
{
	t_param		*tmp;

	if (lst->next)
	{
		tmp = lst->next;
		lst->next = ft_create_param(name);
		lst->next->next = tmp;
	}
	else
		lst->next = ft_create_param(name);
}
