/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:55:36 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/07 03:56:08 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fold_0_normie(t_list **a, t_list **b, int folds, int counter)
{
	int	len_l;
	int	lens[2];

	lens[0] = 4;
	lens[1] = 4;
	len_l = len_list(*a) + len_list(*b);
	if (counter == (int)(len_l / 8))
	{
		lens[0] = round_up((len_l % 8) / 2.0);
		lens[1] = (len_l % 8) / 2;
	}
	if (counter % 2 == 1 || folds == 0)
	{
		executer(a, b, lens, 0);
		insert_start(a, b, lens, 'b');
		return (1);
	}
	else
	{
		executer(a, b, lens, 1);
		swap(lens);
		insert_start(b, a, lens, 'a');
		return (0);
	}
}

int	fold_0(t_list **a, t_list **b, int folds)
{
	int	counter;
	int	len_l;
	int	remainder;
	int	last;

	len_l = len_list(*a) + len_list(*b);
	counter = -1;
	while (++counter < (int)(len_l / 8) + 1)
		last = fold_0_normie(a, b, folds, counter);
	remainder = len_l % 16;
	if (remainder < 8)
		while (remainder-- > 0)
			rrx(a, 'a');
	else
		while (remainder-- > 8)
			rrx(b, 'b');
	return (last);
}
