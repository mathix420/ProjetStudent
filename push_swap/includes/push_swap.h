/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agissing <agissing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:04:57 by agissing          #+#    #+#             */
/*   Updated: 2019/01/14 18:18:14 by agissing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"

typedef struct	s_rot
{
	int		re;
	int		mre;
}				t_rot;

typedef struct	s_op
{
	int			nb;
	struct s_op	*next;
}				t_op;

typedef struct	s_sort
{
	int		count;
	int		bc;
	t_op	**op;
}				t_sort;

void			sort_a(t_stack **pila, t_stack **pilb, t_sort v);
void			sort_b(t_stack **pila, t_stack **pilb, t_sort v);

int				ft_isnum(char *str);
int				ft_len(t_stack *pile);
int				ft_moy(t_stack *pile, int max);
int				ft_max(t_stack *pile, t_sort v);
t_stack			*ft_get_last(t_stack *pile);

int				is_ok_a(t_stack *pile, int max);
int				is_ok_b(t_stack *pile, int max);

int				swap_if_a(t_stack *pila);
int				swap_if_b(t_stack *pile);

void			small_sort_a(t_stack **pila, t_sort v);
void			small_sort_b(t_stack **pila, t_stack **pilb, t_sort v);

void			rra_or_ra(int re, t_stack **pila, int l, t_sort v);
void			rrb_or_rb(int re, t_stack **pilb, int l, t_sort v);

void			clean_sorting(t_op *o);
void			print_sorting(t_op *ops);

void			ft_add_op(t_op **op, int nb);
void			ft_free_ops(t_op *op);

void			little_sort(t_stack **pila, t_stack **pilb, t_sort v);
void			rev_check(t_stack **a, t_stack **b, t_sort v);

int				ft_options(int c, char **v, t_stack **stck_a, t_sort *vars);
int				ft_error(void);
int				is_int(char *str);

int				ft_freetab(char **tab);

#endif
