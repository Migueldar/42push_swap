/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:15:19 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/09/05 21:43:47 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("leaks push_swap");
}

//takes number of elements in a list, returns number of folds
//that should be performed to get best optimization
//got the number calculating the derivative
int	n_of_folds(int n) 
{
	return (aprox_or_zero((ft_ln((ft_ln(2) * n) / 3) - 3 * ft_ln(2)) / ft_ln(2)));
}

//TODO
//hardcore 5
//maybe force 100 to 1 fold(6 less moves)
int	main(int argc, char **argv)
{
	//atexit(leaks);
	t_list	*a;
	t_list	*b;
	int		folds;
	int		len;

	a = create_list(argc, argv, 0);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	b = NULL;
	len = len_list(a);
	folds = n_of_folds(len);
	if (ordered_list(a))
		(void) argc;
	else if (len <= 3)
		hardcode_3(&a, len);
	else if (len <= 6)
		hardcode_5(&a, &b);
	else 
	{
		push_half(&a, &b);
		order_n(&a, &b, folds);
		//print_lists(a, b);
		inserter(&a, &b);
	}
	free_list(a);
}
