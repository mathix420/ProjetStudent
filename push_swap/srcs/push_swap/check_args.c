/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:41:39 by agissing          #+#    #+#             */
/*   Updated: 2019/01/12 19:41:48 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_args(char **str, int *val)
{
	int		i;

	i = 0;
	while (str[i])
		if (!ft_isnum(str[i++]))
			return (0);
	*val = i;
	return (1);
}
