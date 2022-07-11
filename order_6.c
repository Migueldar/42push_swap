/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/11 17:22:48 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_6(t_list **a, t_list **b)
{
	while (*a)
	{
		executer(a, b);
		//print_lists(*a, *b);
		insert_to_b(a, b);
		//print_lists(*a, *b);
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
