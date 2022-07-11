/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:39:18 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/11 00:00:40 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//controlar que sean 0 1 o 2
//l array son los primeros elementos de la lista
//r = r, s = s, rr = 4
//th is 0 if cant find third element in list, 1 else
void	how_to_3(t_list *list, char *fill)
{
	int	l[3];
	int	counter;
	int th;

	counter = -1;
	th = 0;
	if (!list || !(list->next))
		return (fill[0] = 0, (void) 42);
	l[0] = list->content;
	l[1] = list->next->content;
	if (list->next->next && ++th)
		l[2] = list->next->next->content;
	if ((l[1] > l[0]))
		fill[++counter] = 's';
	if (th && !(l[1] > l[0] && l[0] > l[2]) && !(l[0] > l[1] && l[1] > l[2]))
	{
		fill[++counter] = 'r';
		fill[++counter] = 's';
		fill[++counter] = '4';
		if ((l[2] > l[0] && l[0] > l[1]) || (l[2] > l[1] && l[1] > l[0]))
			fill[++counter] = 's';
	}
	fill[++counter] = 0;
}

//to insert, adapt big if from inserter
void	insert_to_b(t_list **a, t_list **b)
{
	int rotations;
	int doA;
	int doB;
	int	lenA;

	rotations = 0;
	doA = 0;
	doB = 0;
	lenA = 3;
	if (len_list(*a) < 3)
		lenA = len_list(*a);
	while (rotations < lenA + 3)
	{
		if (*a && ((doA < 3 && ((*a)->content > (*b)->content)) || doB >= 3))
		{
			p(a, b, 'a');
			doA++;
		}
		else
			doB++;
		r(b, 'b');
		rotations++;
	}
}

void	executer(t_list **a, t_list **b)
{
	char how_to_a[6];
	char how_to_b[6];
	int counter1;
	int counter2;

	counter1 = 0;
	counter2 = 0;
	how_to_3(*a, how_to_a);
	how_to_3(*b, how_to_b);
	while (how_to_a[counter1] || how_to_b[counter2])
	{
		if (how_to_a[counter1] == how_to_b[counter2])
		{
			if (how_to_a[counter1] == 's')
				ss(*a, *b);
			else if (how_to_a[counter1] == 'r')
				rr(a, b);
			else if (how_to_a[counter1] == '4')
				rrr(a, b);
			counter1++;
			counter2++;
		}
		else
		{
			if (strlen(how_to_a) > strlen(how_to_b))
			{
				if (how_to_a[counter1] == 's')
					s(*a, 'a');
				else if (how_to_a[counter1] == 'r')
					r(a, 'a');
				else if (how_to_a[counter1] == '4')
					rrx(a, 'a');
				counter1++;
			}
			else
			{
				if (how_to_b[counter2] == 's')
					s(*b, 'b');
				else if (how_to_b[counter2] == 'r')
					r(b, 'b');
				else if (how_to_b[counter2] == '4')
					rrx(b, 'b');
				counter2++;
			}	
		}
	}
}
