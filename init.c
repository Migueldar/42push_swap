/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:10:57 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/21 21:12:55 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//if fail, free the entire list and ret NULL
t_list	*create_list(int argc, char **argv, int start)
{
	t_list	*ret;
	char	**splitted;
	int		status;
	int		elem;

	ret = NULL;
	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		if (!splitted)
			return (NULL);
		ret = create_list(0, splitted, -1);
		free_double_ptr(splitted);
		return (ret);
	}
	while (argv[++start])
	{
		elem = ft_atoi(argv[start], &status);
		if (!status || is_in_list(ret, elem))
			return (free_list(ret), NULL);
		status = add_elem_back(&ret, elem);
		if (!status)
			return (free_list(ret), NULL);
	}
	return (ret);
}

void	push_half(t_list **a, t_list **b)
{
	int	len;
	int	counter;

	counter = 0;
	len = len_list(*a);
	while (counter < len / 2)
	{
		p(a, b, 'b');
		counter++;
	}
}
