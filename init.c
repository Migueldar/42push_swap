/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:10:57 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/17 21:25:24 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_half(t_list **a, t_list **b)
{
	int	len;
	int	counter;

	counter = 0;
	len = len_list(*a);
	while (counter < len / 2)
	{
		p(a, b, 'b');
		counter++;
	}
}
