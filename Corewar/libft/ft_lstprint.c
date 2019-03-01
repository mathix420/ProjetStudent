/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:38:16 by jnoe              #+#    #+#             */
/*   Updated: 2018/11/21 12:06:43 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	write(1, "list content : ", 15);
	ft_putstr(lst->content);
	ft_putchar('\n');
	write(1, "list content_size : ", 20);
	ft_putnbr(lst->content_size);
	ft_putchar('\n');
}
