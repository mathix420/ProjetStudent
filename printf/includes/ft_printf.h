/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:19:20 by agissing          #+#    #+#             */
/*   Updated: 2018/12/10 14:53:42 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

/*
** ------------------------ DEBUG ------------------------
*/

# include <stdio.h>

/*
** -------------------------------------------------------
*/

typedef struct	s_infos
{
	unsigned int	minlength;
	unsigned int	precision;
	unsigned int	data;
	char			*out;
}				t_infos;

int				ft_putchar(char c);
int				ft_putstr(char const *str);
int				ft_isdigit(int c);

int				ft_is_printf_arg(char c);
int				ft_is_printf_conv(char c);
int				ft_is_printf_flag(char c);
void			ft_capin(uint32_t *bytes, int pos);
void			ft_capinod(uint32_t *bytes, int pos);
void			ft_place(uint32_t *bytes, int pos);
t_infos			*ft_getinfos(char **input);

int				ft_putnb(long long nbr, uint64_t base, char *b);
int				ft_putunb(unsigned long long nbr, uint64_t base, char *b);
int				ft_put_ldouble(long double nb, int precision);
int				ft_put_double(double nb, int precision);

int				ft_printf(const char *restrict format, ...);

#endif
