/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:39:18 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/18 23:11:07 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//l array son los primeros elementos de la lista
//r = r, s = s, rr = 4
static char*	how_to_1_2_3(t_list *list, int len)
{
	int	l[3];

	if (len <= 1)
		return ft_strdup("");
	l[0] = list->content;
	l[1] = list->next->content;
	if (len == 2)
	{
		if (l[0] > l[1])
			return ft_strdup("");
		return ft_strdup("s");
	}
	l[2] = list->next->next->content;
	if (l[0] < l[1] && l[1] < l[2])
		return ft_strdup("srs4s");
	if (l[0] < l[2] && l[2] < l[1])
		return ft_strdup("srs4");
	if (l[1] < l[0] && l[0] < l[2])
		return ft_strdup("rs4s");
	if (l[2] < l[0] && l[0] < l[1])
		return ft_strdup("s");
	if (l[1] < l[2] && l[2] < l[0])
		return ft_strdup("rs4");
	else
		return ft_strdup("");
}

// static void	how_to_4_a(t_list *list, int len)
// {
	
// }

// static void	how_to_4_b(t_list *list, int len)
// {
	
// }

static char*	how_to(t_list *list, int len)
{
	return (how_to_1_2_3(list, len));
}

void	executer(t_list **a, t_list **b, int lens[2])
{
	char	*how_to_a;
	char	*how_to_b;
	char	*copy1;
	char	*copy2;

	how_to_a = how_to(*a, lens[0]);
	how_to_b = how_to(*b, lens[1]);
	copy1 = how_to_a;
	copy2 = how_to_b;
	//printf("a: %s, b: %s\n", how_to_a, how_to_b);
	//fflush(NULL);
	while (*how_to_a || *how_to_b)
	{
		if (*how_to_a == *how_to_b)
		{
			if (*how_to_a == 's')
				ss(*a, *b);
			else if (*how_to_a == 'r')
				rr(a, b);
			else if (*how_to_a == '4')
				rrr(a, b);
			how_to_a++;
			how_to_b++;
		}
		else
		{
			if (ft_strlen(how_to_a) > ft_strlen(how_to_b))
			{
				if (*how_to_a == 's')
					s(*a, 'a');
				else if (*how_to_a == 'r')
					r(a, 'a');
				else if (*how_to_a == '4')
					rrx(a, 'a');
				how_to_a++;
			}
			else
			{
				if (*how_to_b == 's')
					s(*b, 'b');
				else if (*how_to_b == 'r')
					r(b, 'b');
				else if (*how_to_b == '4')
					rrx(b, 'b');
				how_to_b++;
			}	
		}
	}
	free(copy1);
	free(copy2);
}
