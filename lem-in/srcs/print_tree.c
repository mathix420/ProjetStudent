/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:45:18 by agissing          #+#    #+#             */
/*   Updated: 2019/02/15 14:21:07 by acompagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_tree(t_node *tree)
{
	int		i;

	i = tree->nb_next - 1;
	while (i > 0)
	{
		print_tree(tree->next++);
		i--;
	}
	ft_putstr(" <- ");
	ft_putstr(tree->room->name);


}
