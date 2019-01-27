/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <kemartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:56:16 by kemartin          #+#    #+#             */
/*   Updated: 2019/01/26 14:10:54 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <libc.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>

# define OPT_L 1
# define OPT_UR 2
# define OPT_A 4
# define OPT_LR 8
# define OPT_T 16
# define OPT_G 32
# define OPT_UA 64
# define OPT_F 128

# define BUFSIZE_LS 1024

typedef struct stat		t_stat;
typedef struct dir		t_dir;
typedef struct passwd	t_pswd;
typedef struct group	t_grp;

typedef struct			s_buf
{
	unsigned		id;
	char			buf[BUFSIZE_LS];
}						t_buf;

typedef struct			s_lst
{
	char			*name;
	t_stat			stat;
	t_pswd			*pswd;
	t_grp			*grp;
	t_dir			*dir;
	char			t;
	struct s_lst	*next;
}						t_lst;

typedef struct			s_param
{
	char			ok;
	char			*name;
	t_lst			**child;
	struct s_param	*next;
}						t_param;

typedef struct			s_struct
{
	char		opt;
	int			nb;
	t_buf		bf;
	t_param		**names;
}						t_struct;

void					ft_putbuff(t_buf *i);
void					ft_addstr(t_buf *i, char *str);
void					ft_addtwostr(t_buf *i, char *str, char *str2);
void					ft_addchar(t_buf *i, char c);
void					ft_addnbr(t_buf *i, int nbr);

void					total(t_buf *i, t_lst *lst);
void					files_err(char *name);

void					leading(int size, char *str, t_buf *i);
void					leading_nbr(int size, int nbr, t_buf *i);

void					ls_rec(t_struct *tab);
void					ls(t_struct *tab);
char					*link_pointer(char *name);

void					ft_lst_push_back(t_lst **lst, char *name, char *source);

char					*join_path(char *path1, char *path2);

void					ft_param_push_back(t_param **lst, char *name);
void					ft_param_push_after(t_param *lst, char *name);

void					get_childs(t_param *params, char opt);
void					simple_print(t_lst *lst, t_buf *i, char opt);
void					list_print(t_lst *lst, char opt, t_buf *i);

void					options(char *str, t_struct *tab);
void					ft_sort(t_lst **lst, char opt);
char					*cut_time_opt(char *str);
char					*write_perms(int perm);
char					*ft_title(char *title, int t);

void					reverse_lst(t_lst **lst);
void					reverse_param(t_param **lst);

#endif
