/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/22 02:05:25 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertt(t_list **f, t_list **t, int lens[2], char cto)
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

void	order_n(t_list **a, t_list **b, int folds)
{
	int	counter;
	int	len_l;
	int	current_fold;
	int	remainder;
	int	lens[2];

	len_l = len_list(*a) + len_list(*b);
	current_fold = -1;
	while (++current_fold <= folds)
	{
		counter = 0;
		lens[0] = 4 * ft_pow(2, current_fold);
		lens[1] = 4 * ft_pow(2, current_fold);
		while (counter < (int)(len_l / (8 * ft_pow(2, current_fold))))
		{
			// printf("bC: %d\n", counter);
			// print_lists(*a, *b);
			if (current_fold == 0 && counter % 2 == 1)
				executer(a, b, lens, 0);
			else if (current_fold == 0)
				executer(a, b, lens, 1);
			if (current_fold == 0)
			{
				if (counter % 2 == 1 || current_fold == folds)
					insert_to_x(a, b, lens, 'b');
				else
					insert_to_x(b, a, lens, 'a');
			}
			else
			{	
				if (counter % 2 == 1 || current_fold == folds)
					insertt(a, b, lens, 'b');
				else
					insertt(b, a, lens, 'a');
			}
			// printf("aC: %d\n", counter);
			// print_lists(*a, *b);
			counter++;
		}
		remainder = len_l % (int)(8 * ft_pow(2, current_fold));
		if (current_fold == 0)
		{
			lens[0] = round_up(remainder / 2.0);
			lens[1] = remainder / 2;
			if (counter % 2 == 1)
				executer(a, b, lens, 0);
			else
				executer(a, b, lens, 1);
		}
		else if (remainder > (4 * ft_pow(2, current_fold)))
			lens[1] = remainder - 4 * ft_pow(2, current_fold);
		else
		{
			lens[0] = remainder;
			lens[1] = 0;
		}
		if (counter % 2 == 1 || current_fold == folds)
		{
			if (current_fold == 0)
				insert_to_x(a, b, lens, 'b');
			else 
				insertt(a, b, lens, 'b');
		}
		else
		{
			int aux;
			aux = lens[0];
			lens[0] = lens[1];	
			lens[1] = aux;
			if (current_fold == 0)
				insert_to_x(b, a, lens, 'a');
			else 
				insertt(b, a, lens, 'a');
		}	
		// printf("Fold: %d\n", current_fold);
		// print_lists(*a, *b);
		if (current_fold == 0)
		{
			rrx(a, 'a');
			rrx(a, 'a');
			rrx(a, 'a');
			rrx(a, 'a');
		}
	}
}

void	insert_to_x(t_list **f, t_list **t, int lens[2], char cto)
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