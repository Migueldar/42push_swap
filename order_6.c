/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/10 23:47:22 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_6(t_list **a, t_list **b)
{
	while (*a)
	{
		executer(a, b);
		print_lists(*a, *b);
		insert_to_b(a, b);
		print_lists(*a, *b);
	}
}
