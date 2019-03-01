/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:54:48 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/22 11:09:29 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*tmp;
	t_list	*beg_list;

	if ((list = (t_list *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	if (lst == NULL)
		return (NULL);
	list = f(lst);
	beg_list = list;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((tmp = (t_list *)malloc(sizeof(*tmp))) == NULL)
			return (NULL);
		tmp = f(lst);
		lst = lst->next;
		list->next = tmp;
		list = list->next;
	}
	list = NULL;
	return (beg_list);
}
