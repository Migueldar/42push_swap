/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:15:19 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/18 03:18:36 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("leaks push_swap");
}

//takes number of elements in a list, returns number of folds
//that should be perform to get best optimization
//got the number calculating the der
int	n_of_folds(int n) 
{
	return (aprox(1.4427 * ft_ln(0.0601123 * (0.72923 * n))));
}

//TODO
//meter split caso "1 2 3 4", contemplar caso de ya ordenados
//hardcode 3, hardcore 5
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
	// print_lists(a, b);
	order_n(&a, &b, folds);
	// print_lists(a, b);
	inserter(&a, &b);
	// print_lists(a, b);
}
