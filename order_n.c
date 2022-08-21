/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/21 01:10:30 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (current_fold == 0)
				executer(a, b, lens);
			if (counter % 2 == 1 || current_fold == folds)
				insert_to_x(a, b, lens, 'b');
			else
				insert_to_x(b, a, lens, 'a');
			// printf("aC: %d\n", counter);
			// print_lists(*a, *b);
			counter++;
		}
		remainder = len_l % (int)(8 * ft_pow(2, current_fold));
		//printf("Remainder: %d \n", remainder);
		//print_lists(*a, *b);
		if (current_fold == 0)
		{
			lens[0] = round_up(remainder / 2.0);
			lens[1] = remainder / 2;
			executer(a, b, lens);
		}
		else if (remainder > (4 * ft_pow(2, current_fold)))
			lens[1] = remainder - 4 * ft_pow(2, current_fold);
		else
		{
			lens[0] = remainder;
			lens[1] = 0;
		}
		if (counter % 2 == 1 || current_fold == folds)
			insert_to_x(a, b, lens, 'b');
		else
		{
			int aux;
			aux = lens[0];
			lens[0] = lens[1];
			lens[1] = aux;
			insert_to_x(b, a, lens, 'a');
		}
		// printf("Fold: %d\n", current_fold);
		// print_lists(*a, *b);
	}
}

void	insert_to_x(t_list **f, t_list **t, int lens[2], char cto)
{
	int	rotations;
	int len_f;
	int len_t;

	len_f = lens[0];
	len_t = lens[1];
	rotations = 0;
	while (rotations < lens[0] + lens[1])
	{
		if ((len_f > 0 && ((*f)->content > (*t)->content)) || len_t <= 0)
		{
			p(f, t, cto);
			len_f--;
		}
		else
			len_t--;
		r(t, cto);
		rotations++;
	}
}
