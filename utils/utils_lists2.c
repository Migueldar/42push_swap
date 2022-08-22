/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 04:03:31 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/22 04:04:27 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	last_elem(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst->content);
}

//remove
void	print_lists(t_list *a, t_list *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("%d  ", a->content);
			a = a->next;
		}
		else
			printf("   ");
		if (b)
		{
			printf("%d", b->content);
			b = b->next;
		}
		printf("\n");
	}
	fflush(NULL);
}
