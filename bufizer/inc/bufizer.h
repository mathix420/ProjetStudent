/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufizer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:35:45 by agissing          #+#    #+#             */
/*   Updated: 2019/03/02 20:24:52 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFIZER_H
# define BUFIZER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

# define BFZ_BUFSIZE 40

# define OPT_S 1
# define OPT_C 1 << 1
# define OPT_D 1 << 2
# define OPT_X 1 << 3
# define OPT_O 1 << 4
# define OPT_B 1 << 5
# define OPT_G 1 << 6

typedef struct		s_bfz
{
	int				i;
	char			buffer[BFZ_BUFSIZE];
	struct s_bfz	*next;
}					t_bfz;

# ifdef MAIN_FILE

t_bfz				*g_buffer = NULL;
t_bfz				*g_current = NULL;

#  else

extern t_bfz		*g_buffer;
extern t_bfz		*g_current;

# endif

// Functions
void				put_str(va_list lst, char *options);
void				put_char(va_list lst, char *options);
void				put_digit(va_list lst, char *options);
void				put_hex(va_list lst, char *options);
void				put_oct(va_list lst, char *options);
void				put_bin(va_list lst, char *options);
void				put_color(va_list lst, char *options);

// Buffer management
void				print_all(int fd);
void				new_buff(void);

// Main
int					bufizer(const char *format, ...);

#endif
