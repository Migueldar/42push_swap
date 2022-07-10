/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:26:13 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/06/28 17:31:05 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//for all the doc, return 42 if operation OK, 0 else
//ra, rb
int	r(t_list **list, const char c)
{
	t_list	*first;
	t_list	*last;

	if (!*list || !((*list)->next))
		return (0);
	if (c == 'a' || c == 'b')
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	first = *list;
	last = *list;
	*list = first->next;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	return (42);
}

//rr
int	rr(t_list **a, t_list **b)
{
	if (r(a, 's') + r(b, 's'))
	{
		write(1, "rr\n", 3);
		return (42);
	}
	return (0);
}

//rra, rrb
int	rrx(t_list **list, const char c)
{
	t_list	*prelast;

	if (!*list || !((*list)->next))
		return (0);
	if (c == 'a' || c == 'b')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	prelast = *list;
	while (prelast->next->next)
		prelast = prelast->next;
	prelast->next->next = *list;
	*list = prelast->next;
	prelast->next = NULL;
	return (42);
}

//rrr
int	rrr(t_list **a, t_list **b)
{
	if (rrx(a, 's') + rrx(b, 's'))
	{
		write(1, "rrr\n", 4);
		return (42);
	}
	return (0);
}
