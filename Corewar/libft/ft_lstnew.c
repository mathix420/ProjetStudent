/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:34:57 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/22 11:27:09 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		return (list);
	}
	if (((list->content =
		(t_list *)malloc(sizeof(*content) * content_size)) == NULL))
		return (NULL);
	ft_memcpy(list->content, (void*)content, content_size);
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
