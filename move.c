/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:08:51 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/05 20:12:30 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_s(t_list **a, t_list **b, char *how_to_ab[2], int list)
{
	if (list == 0)
	{
		s(*a, 'a');
		how_to_ab[0]++;
	}
	else if (list == 1)
	{
		s(*b, 'b');
		how_to_ab[1]++;
	}
	else if (list == 2)
	{
		ss(*a, *b);
		how_to_ab[0]++;
		how_to_ab[1]++;
	}
}

static void	move_r(t_list **a, t_list **b, char *how_to_ab[2], int list)
{
	if (list == 0)
	{
		r(a, 'a');
		how_to_ab[0]++;
	}
	else if (list == 1)
	{
		r(b, 'b');
		how_to_ab[1]++;
	}
	else if (list == 2)
	{
		rr(a, b);
		how_to_ab[0]++;
		how_to_ab[1]++;
	}
}

static void	move_rr(t_list **a, t_list **b, char *how_to_ab[2], int list)
{
	if (list == 0)
	{
		rrx(a, 'a');
		how_to_ab[0]++;
	}
	else if (list == 1)
	{
		rrx(b, 'b');
		how_to_ab[1]++;
	}
	else if (list == 2)
	{
		rrr(a, b);
		how_to_ab[0]++;
		how_to_ab[1]++;
	}
}

//mov: r = r, s = s, rr = 4
//list: 0 a, 1 b, 2 both
void	move_x(t_list **a, t_list **b, char *how_to_ab[2], int list)
{
	char	mov;

	mov = *how_to_ab[0];
	if (list == 1)
		mov = *how_to_ab[1];
	if (mov == 's')
		move_s(a, b, how_to_ab, list);
	else if (mov == 'r')
		move_r(a, b, how_to_ab, list);
	else if (mov == '4')
		move_rr(a, b, how_to_ab, list);
}
