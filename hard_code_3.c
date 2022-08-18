/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:39:18 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/18 02:47:11 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//l array son los primeros elementos de la lista
//r = r, s = s, rr = 4
static void	how_to_3(t_list *list, char *fill, int len)
{
	int	l[3];
	int	counter;

	counter = -1;
	if (len <= 1)
		return (fill[0] = 0, (void) 42);
	l[0] = list->content;
	l[1] = list->next->content;
	if (len == 3)
		l[2] = list->next->next->content;
	if ((l[1] > l[0]))
		fill[++counter] = 's';
	if (len == 3 && !(l[1] > l[0] && l[0] > l[2]) && !(l[0] > l[1] && l[1] > l[2]))
	{
		fill[++counter] = 'r';
		fill[++counter] = 's';
		fill[++counter] = '4';
		if ((l[2] > l[0] && l[0] > l[1]) || (l[2] > l[1] && l[1] > l[0]))
			fill[++counter] = 's';
	}
	fill[++counter] = 0;
}

void	insert_to_x(t_list **f, t_list **t, int lens[2], char cto)
{
	int rotations;
	int doF;
	int doT;
	int	lenF;
	int	lenT;

	rotations = 0;
	doF = 0;
	doT = 0;
	lenF = lens[0];
	lenT = lens[1];
	while (rotations < lenF + lenT)
	{
		if ((doF < lenF && ((*f)->content > (*t)->content)) || doT >= lenT)
		{
			p(f, t, cto);
			doF++;
		}
		else
			doT++;
		r(t, cto);
		rotations++;
	}
}

void	executer(t_list **a, t_list **b, int lens[2])
{
	char how_to_a[6];
	char how_to_b[6];
	int counter1;
	int counter2;

	counter1 = 0;
	counter2 = 0;
	how_to_3(*a, how_to_a, lens[0]);
	how_to_3(*b, how_to_b, lens[1]);
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
			if (strlen(&how_to_a[counter1]) > strlen(&how_to_b[counter2]))
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
