/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:59:53 by agissing          #+#    #+#             */
/*   Updated: 2019/03/02 20:02:54 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bufizer.h"

void		put_str(va_list lst, char *options)
{
	int		i;
	char	*str;

	i = -1;
	(void)options;
	str = va_arg(lst, char *);
	while (str[++i])
	{
		if (!g_current || g_current->i == BFZ_BUFSIZE)
			new_buff();
		g_current->buffer[g_current->i++] = str[i];
	}
}
