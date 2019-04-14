/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:29 by agissing          #+#    #+#             */
/*   Updated: 2019/04/14 19:39:46 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# ifndef FT_SSL_H
#  include "ft_ssl.h"
# endif

# define BUF_SIZE 6400

struct s_list;
typedef struct s_env	t_env;

typedef struct			s_list
{
	char			str[BUF_SIZE];
	unsigned		size;
	struct s_list	*next;
}						t_list;

void					md5(t_env *env);
int						bit_len(t_list list);

void					push_text(t_list **list, char str[BUF_SIZE], int count);
void					free_text(t_list *list);

void					do_the_work(t_list *lst);

#endif