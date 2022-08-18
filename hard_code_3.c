/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:39:18 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/18 03:13:16 by mde-arpe         ###   ########.fr       */
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
	if (len == 3 && !(l[1] > l[0] && l[0] > l[2])
		&& !(l[0] > l[1] && l[1] > l[2]))
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
	int	rotations;
	int	do_f;
	int	do_t;
	int	len_f;
	int	len_t;

	rotations = 0;
	do_f = 0;
	do_t = 0;
	len_f = lens[0];
	len_t = lens[1];
	while (rotations < len_f + len_t)
	{
		if ((do_f < len_f && ((*f)->content > (*t)->content)) || do_t >= len_t)
		{
			p(f, t, cto);
			do_f++;
		}
		else
			do_t++;
		r(t, cto);
		rotations++;
	}
}

void	executer(t_list **a, t_list **b, int lens[2])
{
	char	how_to_a[6];
	char	how_to_b[6];
	int		counter1;
	int		counter2;

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
