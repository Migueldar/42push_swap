/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:21:42 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/07 04:42:20 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	middle_fold_normie(t_list **a, t_list **b, int current_fold,
	int counter_n_last[2])
{
	int	len_l;
	int	l[2];
	int	remainder;

	len_l = len_list(*a) + len_list(*b);
	l[0] = 4 * ft_pow(2, current_fold);
	l[1] = 4 * ft_pow(2, current_fold);
	if (counter_n_last[0] == (int)(len_l / (8 * ft_pow(2, current_fold))))
	{
		remainder = len_l % (int)(8 * ft_pow(2, current_fold));
		l[1] = 0;
		if (remainder > (4 * ft_pow(2, current_fold)))
			l[1] = remainder - 4 * ft_pow(2, current_fold);
		else
			l[0] = remainder;
	}
	if (counter_n_last[1] == 0)
	{
		if (l[0] == 4 * ft_pow(2, current_fold))
			swap(l);
		return ((void) 42, rev_r(a, l[0], 'a'), insert_mid(a, b, l, 'b'));
	}
	if (l[1] == 0 && l[0] != 4 * ft_pow(2, current_fold))
		swap(l);
	return ((void) 42, swap(l), rev_r(b, l[0], 'b'), insert_mid(b, a, l, 'a'));
}

int	middle_fold(t_list **a, t_list **b, int current_fold, int last)
{
	int	len_l;
	int	lens[2];
	int	counter_n_last[2];

	len_l = len_list(*a) + len_list(*b);
	counter_n_last[0] = -1;
	counter_n_last[1] = last;
	lens[0] = 4 * ft_pow(2, current_fold);
	lens[1] = 4 * ft_pow(2, current_fold);
	while (++(counter_n_last[0])
		< aprox_or_zero(len_l / (16 * ft_pow(2, current_fold))))
	{
		if (last == 0)
			insert_mid(b, a, lens, 'a');
		else
			insert_mid(a, b, lens, 'b');
	}
	counter_n_last[0]--;
	while (++(counter_n_last[0])
		<= (int)(len_l / (8 * ft_pow(2, current_fold))))
		middle_fold_normie(a, b, current_fold, counter_n_last);
	if (last == 0)
		return (1);
	return (0);
}

void	last_fold_normie(t_list **a, t_list **b, int current_fold,
	int counter_n_last[2])
{
	int	lens[2];
	int	len_l;
	int	remainder;

	len_l = len_list(*a) + len_list(*b);
	lens[0] = 4 * ft_pow(2, current_fold);
	lens[1] = 4 * ft_pow(2, current_fold);
	if (counter_n_last[0] == (int)(len_l / (8 * ft_pow(2, current_fold))))
	{
		remainder = len_l % (int)(8 * ft_pow(2, current_fold));
		if (remainder > (4 * ft_pow(2, current_fold)))
			lens[1] = remainder - 4 * ft_pow(2, current_fold);
		else
		{
			lens[0] = remainder;
			lens[1] = 0;
		}
		if (counter_n_last[1] == 0)
			if (lens[0] == (4 * ft_pow(2, current_fold)))
				swap(lens);
		if (counter_n_last[1] == 1)
			if (lens[1] == 0 && lens[0] != 4 * ft_pow(2, current_fold))
				swap(lens);
	}
	insert_last(a, b, lens, 'b');
}

void	last_fold(t_list **a, t_list **b, int current_fold, int last)
{
	int	len_l;
	int	remainder;
	int	counter_n_last[2];

	len_l = len_list(*a) + len_list(*b);
	remainder = len_l % (int)(8 * ft_pow(2, current_fold));
	if ((remainder < (4 * ft_pow(2, current_fold))) && !last)
		while (remainder-- > 0)
			r(a, 'a');
	else if (!last)
		while (remainder-- > (4 * ft_pow(2, current_fold)))
			r(a, 'a');
	counter_n_last[0] = -1;
	counter_n_last[1] = last;
	while (++(counter_n_last[0])
		<= (int)(len_l / (8 * ft_pow(2, current_fold))))
		last_fold_normie(a, b, current_fold, counter_n_last);
}

void	order_n(t_list **a, t_list **b, int folds)
{
	int	current_fold;
	int	last;

	last = fold_0(a, b, folds);
	current_fold = 0;
	while (++current_fold <= folds - 1)
		last = middle_fold(a, b, current_fold, last);
	if (folds > 0)
		last_fold(a, b, current_fold, last);
}
