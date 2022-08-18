/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:52:12 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/17 22:39:59 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
//rm 
#include <string.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int			s(t_list *list, const char c);
int			ss(t_list *a, t_list *b);
int			r(t_list **list, const char c);
int			rr(t_list **a, t_list **b);
int			rrx(t_list **list, const char c);
int			rrr(t_list **a, t_list **b);
int			p(t_list **from, t_list **to, char c);
void		free_list(t_list *first);
t_list		*create_list(char **argv);
void		print_lists(t_list *a, t_list *b);
void		executer(t_list **a, t_list **b, int lens[2]);
void		insert_to_x(t_list **f, t_list **t, int lens[2], char cto);
int			len_list(t_list *list);
void		push_half(t_list **a, t_list **b);
void		order_n(t_list **a, t_list **b, int folds);
void		inserter(t_list **a, t_list **b);
int			aprox(double n);
double		ft_ln(double x);
int			round_up(double n);
double		ft_pow(double x, unsigned int pow);

#endif