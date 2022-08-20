/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:15:19 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/20 23:56:51 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("leaks push_swap");
}

//takes number of elements in a list, returns number of folds
//that should be perform to get best optimization
//got the number calculating the derivative
int	n_of_folds(int n) 
{
	return (aprox((ft_ln((ft_ln(2) * n) / 3) - 3 * ft_ln(2)) / ft_ln(2)));
}

//TODO
//meter split caso "1 2 3 4", contemplar caso de ya ordenados
//hardcode 3, hardcore 5
//comprobar formula que saca numero de folds para numeros muy pequeños
//implementar reverse rotation en el primer paso de cada fold (ahorra 8 + 16 + ... movs)
//buscar optimizaciones para el inserter de 4, igual que las busque para el de 3 (already did, but surely could be better, i will improve if needed)
//maybe force 100 to 1 fold(6 less moves)
int	main(int argc, char **argv)
{
	//atexit(leaks);
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
	b = NULL;
	folds = n_of_folds(len_list(a));
	push_half(&a, &b);
	// print_lists(a, b);
	order_n(&a, &b, folds);
	// print_lists(a, b);
	inserter(&a, &b);
	// print_lists(a, b);
	free_list(a);
}
