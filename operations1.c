/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:15:21 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/06/15 00:30:32 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//for all the doc, return 42 if operation OK, 0 else
//sa, sb
int	s(t_list *list, const char c)
{
	int	aux;

	if (!list || !list->next)
		return (0);
	if (c == 'a' || c == 'b')
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
	aux = list->content;
	list->content = list->next->content;
	list->next->content = aux;
	return (42);
}

//ss
int	ss(t_list *a, t_list *b)
{
	if (s(a, 's') + s(b, 's'))
	{
		write(1, "ss\n", 3);
		return (42);
	}	
	return (0);
}

//pa, pb 
//take element from, put it in to 
int	p(t_list **from, t_list **to, char c)
{
	t_list	*aux;
	t_list	*aux2;

	if (!*from)
		return (0);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
	aux2 = (*from)->next;
	aux = *to;
	*to = *from;
	(*to)->next = aux;
	*from = aux2;
	return (42);
}
