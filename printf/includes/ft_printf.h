/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:19:20 by agissing          #+#    #+#             */
/*   Updated: 2018/12/16 16:31:08 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define M_CSP (7 << 11)
# define M_HEXS (3 << 4)
# define M_DIOUX (0x3f << 4)
# define M_OUX (0xf0)
# define M_INT (3 << 8)

# define M_PRES (1 << 2)
# define M_MIN_SIZE (1 << 3)

# define M_ERROR (1)
# define M_UHEX (1 << 4)
# define M_LHEX (1 << 5)
# define M_UNSI (1 << 6)
# define M_OCT (1 << 7)
# define M_DBL (1 << 10)
# define M_PTR (1 << 11)
# define M_STR (1 << 12)
# define M_CHR (1 << 13)
# define M_PRCT (1 << 14)
# define M_BIN (1 << 15)
# define M_BOOL (1 << 16)
# define M_UNI (1 << 17)
# define M_ZBS (1 << 18)

# define MF_ALL (0xf8 << 24)
# define MF_UL (1 << 27)
# define MF_HH (1 << 28)
# define MF_H (1 << 29)
# define MF_LL (1 << 30)
# define MF_L (1 << 31)

# define M_HASH (1 << 26)
# define M_ZERO (1 << 25)
# define M_LEFT (1 << 24)
# define M_PLUS (1 << 23)
# define M_SPC (1 << 22)

# define M_DIX (M_INT + M_HEXS)

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
	char			*bs;
	uint64_t		bn;
}				t_infos;

int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_isdigit(int c);
int				ft_putpstr(char *s, t_infos *i, int disp);

uint64_t		ft_uconv(t_infos *i, uint64_t nbr);
int64_t			ft_conv(t_infos *i, int64_t nbr);

int				ft_puthex(t_infos *i, uint64_t nbr, int d);
int				ft_putoct(t_infos *i, uint64_t nbr, int d);
int				ft_putbin(t_infos *i, uint64_t nbr, int d);
int				ft_putb32(t_infos *i, uint64_t nbr, int d);
int				ft_putdi(t_infos *i, int64_t nbr, int d);
int				ft_putuns(t_infos *i, uint64_t nbr, int d);
int				ft_putstring(t_infos *i, char *str, int d);
int				ft_putptr(t_infos *i, void *addr, int d);
int				ft_putpercent(t_infos *i, int d);

int				ft_is_printf_arg(char c);
int				ft_is_printf_conv(char c);
int				ft_is_printf_flag(char c);
void			ft_capin(uint32_t *bytes, int pos);
void			ft_capinod(uint32_t *bytes, int pos);
void			ft_place(uint32_t *bytes, int pos);
void			ft_remove(uint32_t *bytes, int pos);
void			ft_free(t_infos **i);

t_infos			*ft_getinfos(char **input, t_infos **oldi);

int				ft_more(t_infos *i, unsigned count, int d);
int				ft_putnb(long long nbr, uint64_t base, char *b, int d);
int				ft_putunb(uint64_t nbr, t_infos *i, int d);
int				ft_put_ldouble(long double nb, int p, int d, t_infos *i);

int				ft_printf(const char *restrict format, ...);

#endif
