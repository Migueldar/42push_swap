/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:39:18 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/22 00:11:46 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//l array son los primeros elementos de la lista
//r = r, s = s, rr = 4
static char	*how_to_1_2_3(t_list *list, int len, int opp)
{
	int	l[3];

	if (len <= 1)
		return (ft_strdup(""));
	l[0] = list->content;
	l[1] = list->next->content;
	if (len == 2)
	{
		if (op(l[0], l[1], opp))
			return (ft_strdup("s"));
		return (ft_strdup(""));
	}
	l[2] = list->next->next->content;
	if (op(l[0], l[1], opp) && op(l[1], l[2], opp))
		return (ft_strdup("srs4s"));
	if (op(l[0], l[2], opp) && op(l[2], l[1], opp))
		return (ft_strdup("srs4"));
	if (op(l[1], l[0], opp) && op(l[0], l[2], opp))
		return (ft_strdup("rs4s"));
	if (op(l[2], l[0], opp) && op(l[0], l[1], opp))
		return (ft_strdup("s"));
	if (op(l[1], l[2], opp) && op(l[2], l[0], opp))
		return (ft_strdup("rs4"));
	return (ft_strdup(""));
}

static char	*how_to_4_b(int l[4], int opp)
{
	if (op(l[1], l[2], opp) && op(l[2], l[0], opp) && op(l[0], l[3], opp))
		return (ft_strdup("rsrs4s4s"));
	if (op(l[1], l[3], opp) && op(l[3], l[0], opp) && op(l[0], l[2], opp))
		return (ft_strdup("rsrs44s"));
	if (op(l[2], l[1], opp) && op(l[1], l[0], opp) && op(l[0], l[3], opp))
		return (ft_strdup("rrs4s4s"));
	if (op(l[3], l[1], opp) && op(l[1], l[0], opp) && op(l[0], l[2], opp))
		return (ft_strdup("rs4s"));
	if (op(l[2], l[3], opp) && op(l[3], l[0], opp) && op(l[0], l[1], opp))
		return (ft_strdup("rrs44s"));
	if (op(l[3], l[2], opp) && op(l[2], l[0], opp) && op(l[0], l[1], opp))
		return (ft_strdup("s"));
	if (op(l[1], l[2], opp) && op(l[2], l[3], opp) && op(l[3], l[0], opp))
		return (ft_strdup("rsrs4s4"));
	if (op(l[1], l[3], opp) && op(l[3], l[2], opp) && op(l[2], l[0], opp))
		return (ft_strdup("rsrs44"));
	if (op(l[2], l[1], opp) && op(l[1], l[3], opp) && op(l[3], l[0], opp))
		return (ft_strdup("rrs4s4"));
	if (op(l[3], l[1], opp) && op(l[1], l[2], opp) && op(l[2], l[0], opp))
		return (ft_strdup("rs4"));
	if (op(l[2], l[3], opp) && op(l[3], l[1], opp) && op(l[1], l[0], opp))
		return (ft_strdup("rrs44"));
	return (ft_strdup(""));
}

static char	*how_to_4_a(int l[4], int opp)
{
	if (op(l[0], l[1], opp) && op(l[1], l[2], opp) && op(l[2], l[3], opp))
		return (ft_strdup("srsrs44srs4s"));
	if (op(l[0], l[1], opp) && op(l[1], l[3], opp) && op(l[3], l[2], opp))
		return (ft_strdup("srsrs44srs4"));
	if (op(l[0], l[2], opp) && op(l[2], l[1], opp) && op(l[1], l[3], opp))
		return (ft_strdup("srsrs4s4s"));
	if (op(l[0], l[3], opp) && op(l[3], l[1], opp) && op(l[1], l[2], opp))
		return (ft_strdup("srsrs44s"));
	if (op(l[0], l[2], opp) && op(l[2], l[3], opp) && op(l[3], l[1], opp))
		return (ft_strdup("srsrs4s4"));
	if (op(l[0], l[3], opp) && op(l[3], l[2], opp) && op(l[2], l[1], opp))
		return (ft_strdup("srsrs44"));
	if (op(l[1], l[0], opp) && op(l[0], l[2], opp) && op(l[2], l[3], opp))
		return (ft_strdup("rsrs44srs4s"));
	if (op(l[1], l[0], opp) && op(l[0], l[3], opp) && op(l[3], l[2], opp))
		return (ft_strdup("rsrs44srs4"));
	if (op(l[2], l[0], opp) && op(l[0], l[1], opp) && op(l[1], l[3], opp))
		return (ft_strdup("rrs44srs4s"));
	if (op(l[3], l[0], opp) && op(l[0], l[1], opp) && op(l[1], l[2], opp))
		return (ft_strdup("srs4s"));
	if (op(l[2], l[0], opp) && op(l[0], l[3], opp) && op(l[3], l[1], opp))
		return (ft_strdup("rrs44srs4"));
	if (op(l[3], l[0], opp) && op(l[0], l[2], opp) && op(l[2], l[1], opp))
		return (ft_strdup("srs4"));
	return (how_to_4_b(l, opp));
}

static char	*how_to(t_list *list, int len, int opp)
{
	int	l[4];

	if (len <= 3)
		return (how_to_1_2_3(list, len, opp));
	l[0] = list->content;
	l[1] = list->next->content;
	l[2] = list->next->next->content;
	l[3] = list->next->next->next->content;
	return  (how_to_4_a(l, opp));
}

void	executer(t_list **a, t_list **b, int lens[2], int opp)
{
	char	*how_to_a;
	char	*how_to_b;
	char	*copy1;
	char	*copy2;

	how_to_a = how_to(*a, lens[0], opp);
	how_to_b = how_to(*b, lens[1], opp);
	copy1 = how_to_a;
	copy2 = how_to_b;
	// printf("a: %s, b: %s\n", how_to_a, how_to_b);
	// fflush(NULL);
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
			if (ft_strlen(how_to_a) > ft_strlen(how_to_b) || (ft_strlen(how_to_a) == ft_strlen(how_to_b) && *how_to_a == 's'))
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
	// printf("exec:\n");
	// print_lists(*a, *b);
	free(copy1);
	free(copy2);
}
