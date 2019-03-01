/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:54:14 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/12 17:36:22 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	while (*alst != NULL)
	{
		list = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = list;
	}
}
