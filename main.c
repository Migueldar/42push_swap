/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:15:19 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/17 05:14:09 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("leaks push_swap");
}

//takes number of elements in a list, returns number of folds
//that should be perform to get best optimization
int	n_of_folds(int n) {
	double	ln2;

	ln2 = 0.693147;
	return (aprox(ft_ln((n-1.0)*ln2/18.0)/ln2));
}

//meter split caso "1 2 3 4", contemplar caso de ya ordenados
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		folds;

	(void) argc;
	a = create_list(argv);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	folds = n_of_folds(len_list(a));
	b = NULL;
	push_half(&a, &b);
	// //print_lists(a, b);
	order_n(&a, &b, folds);
	// print_lists(a, b);
	// inserter(&a, &b);
	// print_lists(a, b);
}
