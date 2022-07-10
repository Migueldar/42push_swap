/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:30:10 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/10 23:19:58 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_list(t_list *list)
{
	int counter;

	counter = 0;
	while (list)
	{
		list = list->next;
		counter++;
	}
	return (counter);
}
