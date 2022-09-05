/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/05 03:28:31 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_start(t_list **f, t_list **t, int lens[2], char cto)
{
	int len_f;
	int len_t;
	int	opp;

	len_f = lens[0];
	len_t = lens[1];
	opp = 0;
	if (cto == 'b')
		opp = 1;
	while (len_f > 0 || len_t > 0)
	{
		if ((len_f > 0 && op((*f)->content, (*t)->content, opp)) || len_t <= 0)
		{
			p(f, t, cto);
			len_f--;
		}
		else
			len_t--;
		r(t, cto);
	}
}

void	insert_middle(t_list **f, t_list **t, int lens[2], char cto)
{
	int len_f;
	int len_t;
	int	opp;
	int	counter = -1;
	char cfrom = 'a';

	if (cto == 'a')
		cfrom = 'b';
	len_f = lens[0];
	len_t = lens[1];
	opp = 1;
		while (++counter < len_f)
			rrx(f, cfrom);
	if (cto == 'b')
		opp = 0;
	while (len_f > 0 || len_t > 0)
	{
		if ((len_f > 0 && op((*f)->content, last_elem(*t), opp)) || len_t <= 0)
		{
			p(f, t, cto);
			len_f--;
		}
		else
		{
			rrx(t, cto);
			len_t--;
		}
	}
}

void	insert_last(t_list **f, t_list **t, int lens[2], char cto)
{
	int len_f;
	int len_t;
	int	opp;
	char cfrom = 'a';

	if (cto == 'a')
		cfrom = 'b';
	len_f = lens[0];
	len_t = lens[1];
	opp = 1;
	if (cto == 'b')
		opp = 0;
	while (len_f > 0 || len_t > 0)
	{
		if ((len_f > 0 && op((*f)->content, last_elem(*t), opp)) || len_t <= 0)
		{
			p(f, t, cto);
			len_f--;
		}
		else
		{
			rrx(t, cto);
			len_t--;
		}
	}
}

void	fold_0(t_list **a, t_list **b, int folds)
{
	int	counter;
	int	lens[2];
	int	len_l;
	int remainder;

	len_l = len_list(*a) + len_list(*b);
	counter = -1;
	lens[0] = 4;
	lens[1] = 4;
	while (++counter < (int)(len_l / 8) + 1)
	{
		if (counter == (int)(len_l / 8))
		{
			remainder = len_l % 8;
			lens[0] = round_up(remainder / 2.0);
			lens[1] = remainder / 2;
		}
		if (counter % 2 == 1 || folds == 0)
		{
			executer(a, b, lens, 0);
			insert_start(a, b, lens, 'b');
		}
		else
		{
			executer(a, b, lens, 1);
			swap(lens);
			insert_start(b, a, lens, 'a');
		}
	}
	remainder = len_l % 16;
	if (remainder < 8)
		while (remainder-- > 0)
			rrx(a, 'a');
	else 
		while (remainder-- > 8)
			rrx(b, 'b');
	//return (counter);
}

void	last_fold(t_list **a, t_list **b, int current_fold)
{
	int	counter;
	int	lens[2];
	int	len_l;
	int remainder;

	len_l = len_list(*a) + len_list(*b);
	remainder = len_l % (int)(8 * ft_pow(2, current_fold));
	if (remainder < (4 * ft_pow(2, current_fold)))
		while (remainder-- > 0)
			r(a, 'a');
	counter = -1;
	lens[0] = 4 * ft_pow(2, current_fold);
	lens[1] = 4 * ft_pow(2, current_fold);
	while (++counter < (int)(len_l / (8 * ft_pow(2, current_fold))) + 1)
	{
		if (counter == (int)(len_l / (8 * ft_pow(2, current_fold))))
		{
			remainder = len_l % (int)(8 * ft_pow(2, current_fold));
			if (remainder > (4 * ft_pow(2, current_fold)))
				lens[1] = remainder - 4 * ft_pow(2, current_fold);
			else
			{
				lens[0] = remainder;
				lens[1] = 0;
			}
		}
		insert_last(a, b, lens, 'b');
	}
}

void	order_n(t_list **a, t_list **b, int folds)
{
	int	counter;
	int	len_l;
	int	current_fold;
	int	remainder;
	int	lens[2];

	len_l = len_list(*a) + len_list(*b);
	//print_lists(*a, *b);
	fold_0(a, b, folds);
	//printf("After fold 0:\n");
	//print_lists(*a, *b);
	current_fold = 0;
	while (++current_fold <= folds - 1)
	{
		counter = -1;
		lens[0] = 4 * ft_pow(2, current_fold);
		lens[1] = 4 * ft_pow(2, current_fold);
		while (++counter < (int)(len_l / (8 * ft_pow(2, current_fold))) + 1)
		{
			if (counter == (int)(len_l / (8 * ft_pow(2, current_fold))))
			{
				remainder = len_l % (int)(8 * ft_pow(2, current_fold));
				if (remainder > (4 * ft_pow(2, current_fold)))
					lens[1] = remainder - 4 * ft_pow(2, current_fold);
				else
				{
					lens[0] = remainder;
					lens[1] = 0;
				}
			}
			if (counter % 2 == 1)
				insert_middle(a, b, lens, 'b');
			else
			{
				swap(lens);
				insert_middle(b, a, lens, 'a');
			}
		}
		//printf("After fold %d:\n", current_fold);
		//print_lists(*a, *b);
	}
	if (folds > 0)
		last_fold(a, b, folds);
	// printf("After last:\n");
	// print_lists(*a, *b);
}
