/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation_destruction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:24:12 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/06/15 01:10:51 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_list *a, t_list *b)
{
	//remove
	while (a || b)
	{
		if (a)
		{
			printf("%d  ", a->content);
			a = a->next;
		}
		else
			printf("   ");
		if (b)
		{
			printf("%d", b->content);
			b = b->next;
		}
		printf("\n");
	}
	printf("\n");
	fflush(NULL);
}

//0 exit if malloc wrong, 42 else
static int	add_elem_back(t_list **first, int n)
{
	t_list	*new;
	t_list	*aux;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = n;
	new->next = NULL;
	if (!*first)
	{
		*first = new;
		return (42);
	}
	aux = *first;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
	return (42);
}

//counter acts as strlen
//status 0 if fail
static int	ft_atoi(const char *str, int *status)
{
	int				minus;
	long int		ret;
	int				counter;

	ret = 0;
	minus = 0;
	counter = 0;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			minus++;
	while (*str)
	{
		if (!(*str <= '9' && *str >= '0'))
			return (*status = 0, 0);
		ret = ret * 10 + (*str++ - '0');
		counter++;
	}
	if (counter > 10 || (ret > 0x7fffffff && !minus)
		|| (ret > 0x80000000 && minus))
		return (*status = 0, 0);
	if (minus)
		ret *= -1;
	return (*status = 42, ret);
}

void	free_list(t_list *first)
{
	t_list	*aux;

	while (first != NULL)
	{
		aux = first;
		first = first->next;
		free(aux);
	}
}

static int	is_in_list(t_list *list, int elem)
{
	while (list != NULL)
	{
		if (list->content == elem)
			return (1);
		list = list->next;
	}
	return (0);
}

//if fail, free the entire list and ret NULL
t_list	*create_list(char **argv)
{
	t_list	*ret;
	int		status;
	int		elem;

	ret = NULL;
	while (*(++argv))
	{
		elem = ft_atoi(*argv, &status);
		if (!status || is_in_list(ret, elem))
			return (free_list(ret), NULL);
		status = add_elem_back(&ret, elem);
		if (!status)
			return (free_list(ret), NULL);
	}
	return (ret);
}
