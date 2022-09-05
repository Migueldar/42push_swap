/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:03:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/05 21:40:35 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hardcode_3(t_list **a, int len)
{
	int	l[3];

	if (len == 2)
	{
		s(*a, 'a');
		return ;
	}
	l[0] = (*a)->content;
	l[1] = (*a)->next->content;
	l[2] = (*a)->next->next->content;
	if ((l[0] < l[2] && l[2] < l[1]) || (l[1] < l[0] && l[0] < l[2])
		|| (l[2] < l[1] && l[1] < l[0]))
		s(*a, 'a');
	if ((l[0] < l[2] && l[2] < l[1]) || (l[1] < l[2] && l[2] < l[0]))
		r(a, 'a');
	if ((l[2] < l[0] && l[0] < l[1]) || (l[2] < l[1] && l[1] < l[0]))
		rrx(a, 'a');
}

char	*how_to_3(t_list *list, int opp)
{
	int	l[3];

	if (!list || !(list->next))
		return (ft_strdup(""));
	l[0] = list->content;
	l[1] = list->next->content;
	if (!(list->next->next))
	{
		if (op(l[1], l[0], opp))
			return (ft_strdup("s"));
		return (ft_strdup(""));
	}
	l[2] = list->next->next->content;
	if (op(l[0], l[1], opp) && op(l[1], l[2], opp))
		return (ft_strdup(""));
	if (op(l[0], l[2], opp) && op(l[2], l[1], opp))
		return (ft_strdup("sr"));
	if (op(l[1], l[0], opp) && op(l[0], l[2], opp))
		return (ft_strdup("s"));
	if (op(l[2], l[0], opp) && op(l[0], l[1], opp))
		return (ft_strdup("4"));
	if (op(l[1], l[2], opp) && op(l[2], l[0], opp))
		return (ft_strdup("r"));
	return (ft_strdup("s4"));
}

void	hardcode_5(t_list **a, t_list **b)
{
	char	*how_to_ab[2];
	char	*copy1;
	char	*copy2;

	push_half(a, b);
	how_to_ab[0] = how_to_3(*a, 0);
	how_to_ab[1] = how_to_3(*b, 1);
	copy1 = how_to_ab[0];
	copy2 = how_to_ab[1];
	while (*how_to_ab[0] || *how_to_ab[1])
	{
		if (*how_to_ab[0] == *how_to_ab[1])
			move_x(a, b, how_to_ab, 2);
		else
		{
			if (ft_strlen(how_to_ab[0]) > ft_strlen(how_to_ab[1]))
				move_x(a, b, how_to_ab, 0);
			else
				move_x(a, b, how_to_ab, 1);
		}
	}
	free(copy1);
	free(copy2);
	inserter(a, b);
}
