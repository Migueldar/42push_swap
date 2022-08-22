/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:55:28 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/22 04:03:41 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	len_list(t_list *list)
{
	int	counter;

	counter = 0;
	while (list)
	{
		list = list->next;
		counter++;
	}
	return (counter);
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

void	free_list(t_list *first)
{
	t_list	*aux;

	while (first != NULL)
	{
		aux = first;
		first = first->next;
		free(aux);
	}
}

int	is_in_list(t_list *list, int elem)
{
	while (list != NULL)
	{
		if (list->content == elem)
			return (1);
		list = list->next;
	}
	return (0);
}

//0 exit if malloc wrong, 42 else
int	add_elem_back(t_list **first, int n)
{
	t_list	*new;
	t_list	*aux;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = n;
	new->next = NULL;
	if (!*first)
	{
		*first = new;
		return (42);
	}
	aux = *first;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
	return (42);
}
