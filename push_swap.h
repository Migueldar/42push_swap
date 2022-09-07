/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:52:12 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/07 04:42:47 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

//MOVES
int			s(t_list *list, const char c);
int			ss(t_list *a, t_list *b);
int			r(t_list **list, const char c);
int			rr(t_list **a, t_list **b);
int			rrx(t_list **list, const char c);
int			rrr(t_list **a, t_list **b);
int			p(t_list **from, t_list **to, char c);

//INIT
void		push_half(t_list **a, t_list **b);

//EXECUTER
void		executer(t_list **a, t_list **b, int lens[2], int opp);
void		move_x(t_list **a, t_list **b, char *how_to_ab[2], int list);

//INSERTER
void		inserter(t_list **a, t_list **b);

//HARDCODE
void		hardcode_3(t_list **a, int len);
void		hardcode_5(t_list **a, t_list **b);

//INSERTER MOVE, FOLD_0
void		insert_start(t_list **f, t_list **t, int lens[2], char cto);
void		insert_mid(t_list **f, t_list **t, int lens[2], char cto);
void		insert_last(t_list **f, t_list **t, int lens[2], char cto);
void		rev_r(t_list **f, int len_f, char cfrom);
int			fold_0(t_list **a, t_list **b, int folds);

//UTILS
void		free_list(t_list *first);
t_list		*create_list(int argc, char **argv, int start);
void		print_lists(t_list *a, t_list *b);
void		insert_to_x(t_list **f, t_list **t, int lens[2], char cto);
int			len_list(t_list *list);
void		order_n(t_list **a, t_list **b, int folds);
int			aprox_or_zero(double n);
double		ft_ln(double x);
int			round_up(double n);
double		ft_pow(double x, unsigned int pow);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
int			ordered_list(t_list *a);
int			ft_atoi(const char *str, int *status);
int			is_in_list(t_list *list, int elem);
int			add_elem_back(t_list **first, int n);
void		free_double_ptr(char **ptr);
void		*ft_calloc(size_t count, size_t size);
int			op(int a, int b, int opp);
int			last_elem(t_list *lst);
void		swap(int arr[2]);

#endif