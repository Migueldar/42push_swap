/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/19 04:52:14 by mde-arpe         ###   ########.fr       */
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
		lens[0] = 3 * ft_pow(2, current_fold);
		lens[1] = 3 * ft_pow(2, current_fold);
		while (counter < (int)(len_l / (6 * ft_pow(2, current_fold))))
		{
			if (current_fold == 0)
				executer(a, b, lens);
			if (counter % 2 == 1 || current_fold == folds)
				insert_to_x(a, b, lens, 'b');
			else
				insert_to_x(b, a, lens, 'a');
			// printf("C: %d\n", counter);
			// print_lists(*a, *b);
			counter++;
		}
		remainder = len_l % (int)(6 * ft_pow(2, current_fold));
		//printf("Remainder: %d \n", remainder);
		//print_lists(*a, *b);
		if (current_fold == 0)
		{
			lens[0] = round_up(remainder / 2.0);
			lens[1] = remainder / 2;
			executer(a, b, lens);
		}
		else if (remainder > (3 * ft_pow(2, current_fold)))
			lens[1] = remainder - 3 * ft_pow(2, current_fold);
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

int	ordered_list(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	inserter(t_list **a, t_list **b)
{
	t_list *aux;

	while (*b)
	{
		aux = *a;
		while (aux && aux->next)
			aux = aux->next;
		if (!*a || !((*a)->next) || (((*a)->content > (*b)->content) && ((*b)->content > aux->content)) ||
			(ordered_list(*a) && ((((*b)->content > (*a)->content) && ((*b)->content > aux->content)) ||
			(((*b)->content < (*a)->content) && ((*b)->content < aux->content)))))
			p(b, a, 'a');
		else
			rrx(a, 'a');
		//print_lists(*a, *b);
	}
	while (!ordered_list(*a))
		rrx(a, 'a');
}
