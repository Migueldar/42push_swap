/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_fold.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:47:31 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/07 04:42:38 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_start(t_list **f, t_list **t, int lens[2], char cto)
{
	int	len_f;
	int	len_t;
	int	opp;

	len_f = lens[0];
	len_t = lens[1];
	opp = 0;
	if (cto == 'b')
		opp = 1;
	while (len_f > 0 || len_t > 0)
	{
		if ((len_f > 0 && op((*f)->content, (*t)->content, opp)) || len_t <= 0)
		{
			p(f, t, cto);
			len_f--;
		}
		else
			len_t--;
		r(t, cto);
	}
}

void	insert_mid(t_list **f, t_list **t, int lens[2], char cto)
{
	int	len_f;
	int	len_t;
	int	opp;
	int	counter;

	len_f = lens[0];
	len_t = lens[1];
	opp = 1;
	counter = -1;
	if (cto == 'b')
		opp = 0;
	while (len_f > 0 || len_t > 0)
	{
		if ((len_f > 0 && op((*f)->content, last_elem(*t), opp)) || len_t <= 0)
		{
			p(f, t, cto);
			len_f--;
		}
		else
		{
			rrx(t, cto);
			len_t--;
		}
	}
}

void	insert_last(t_list **f, t_list **t, int lens[2], char cto)
{
	int	len_f;
	int	len_t;
	int	opp;

	len_f = lens[0];
	len_t = lens[1];
	opp = 1;
	if (cto == 'b')
		opp = 0;
	while (len_f > 0 || len_t > 0)
	{
		if ((len_f > 0 && op((*f)->content, last_elem(*t), opp)) || len_t <= 0)
		{
			p(f, t, cto);
			len_f--;
		}
		else
		{
			rrx(t, cto);
			len_t--;
		}
	}
}

void	rev_r(t_list **f, int len_f, char cfrom)
{
	while (len_f--)
		rrx(f, cfrom);
}
