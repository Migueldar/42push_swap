/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:52:12 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/21 01:51:31 by mde-arpe         ###   ########.fr       */
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
int			aprox_or_pos(double n);
double		ft_ln(double x);
int			round_up(double n);
double		ft_pow(double x, unsigned int pow);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
int			ordered_list(t_list *a);
void		hardcode_3(t_list **a, int len);
void		hardcode_5(t_list **a, t_list **b);
char		**ft_split(char const *s, char c);

#endif