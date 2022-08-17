/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:39:18 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/17 21:28:24 by mde-arpe         ###   ########.fr       */
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

void	executer(t_list **f, t_list **t)
{
	char how_to_a[6];
	char how_to_b[6];
	int counter1;
	int counter2;

	counter1 = 0;
	counter2 = 0;
	how_to_3(*f, how_to_a);
	how_to_3(*t, how_to_b);
	while (how_to_a[counter1] || how_to_b[counter2])
	{
		if (how_to_a[counter1] == how_to_b[counter2])
		{
			if (how_to_a[counter1] == 's')
				ss(*f, *t);
			else if (how_to_a[counter1] == 'r')
				rr(f, t);
			else if (how_to_a[counter1] == '4')
				rrr(f, t);
			counter1++;
			counter2++;
		}
		else
		{
			if (strlen(how_to_a) > strlen(how_to_b))
			{
				if (how_to_a[counter1] == 's')
					s(*f, 'f');
				else if (how_to_a[counter1] == 'r')
					r(f, 'f');
				else if (how_to_a[counter1] == '4')
					rrx(f, 'f');
				counter1++;
			}
			else
			{
				if (how_to_b[counter2] == 's')
					s(*t, 't');
				else if (how_to_b[counter2] == 'r')
					r(t, 't');
				else if (how_to_b[counter2] == '4')
					rrx(t, 't');
				counter2++;
			}	
		}
	}
}
