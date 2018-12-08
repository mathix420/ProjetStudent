/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:19:20 by agissing          #+#    #+#             */
/*   Updated: 2018/12/08 11:58:22 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

/* ------------------------ DEBUG ------------------------ */

# include <stdio.h>

/* ------------------------------------------------------- */

typedef struct	s_infos
{
	unsigned int	minlength;
	unsigned int	precision;
	unsigned int	data;
}				t_infos;

int				ft_is_printf_arg(char c);
int				ft_is_printf_conv(char c);
int				ft_is_printf_flag(char c);
void			ft_capin(uint32_t *bytes, int pos);
void			ft_capinod(uint32_t *bytes, int pos);
void			ft_place(uint32_t *bytes, int pos);
t_infos			*ft_getinfos(char *input);

#endif
