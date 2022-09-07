/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:10:09 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/06 07:29:55 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inserter(t_list **a, t_list **b)
{
	t_list	*aux;

	while (*b)
	{
		aux = *a;
		while (aux && aux->next)
			aux = aux->next;
		if (!*a || !((*a)->next)
			|| (((*a)->content > (*b)->content)
				&& ((*b)->content > aux->content))
			|| (ordered_list(*a)
				&& ((((*b)->content > (*a)->content)
						&& ((*b)->content > aux->content))
					|| (((*b)->content < (*a)->content)
						&& ((*b)->content < aux->content)))))
			p(b, a, 'a');
		else
			rrx(a, 'a');
	}
	while (!ordered_list(*a))
		rrx(a, 'a');
}
