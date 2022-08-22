/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 01:03:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/22 04:05:24 by mde-arpe         ###   ########.fr       */
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

void	hardcode_5(t_list **a, t_list **b)
{
	(void) a;
	(void) b;
}
