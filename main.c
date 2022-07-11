/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:15:19 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/07/10 23:54:54 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leaks()
{
	system("leaks push_swap");
}


//meter split caso "1 2 3 4", contemplar caso de ya ordenados
int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	(void) argc;
	a = create_list(argv);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	push_half(&a, &b);
	//print_lists(a, b);
	order_6(&a, &b);
	//print_lists(a, b);
	inserter(&a, &b);
	//print_lists(a, b);
}
