/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/17 05:20:14 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_n(t_list **a, t_list **b, int folds)
{
	int	counter;
	int	len_l;
	int	current_fold;

	len_l = len_list(*a);
	current_fold = -1;
	while (++current_fold <= folds)
	{
		counter = 0;
		while (counter < round_up(len_l / (3.0 * ft_pow(2, current_fold))))
		{
			if (current_fold == 0)
				executer(a, b);
			if (counter % 2 == 0)
				insert_to_x(a, b, current_fold, 'b');
			else 
				insert_to_x(b, a, current_fold, 'a');
			counter++;
		}
		printf("Fold: %d\n", current_fold);
		print_lists(*a, *b);
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
	}
	while (!ordered_list(*a))
		rrx(a, 'a');
}
