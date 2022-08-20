/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:30:10 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/17 04:57:18 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_list(t_list *list)
{
	int	counter;

	counter = 0;
	while (list)
	{
		list = list->next;
		counter++;
	}
	return (counter);
}

int	aprox(double n)
{
	int	floor;

	floor = (int) n;
	if ((double) floor + 0.5 > n)
		return (floor);
	return (floor + 1);
}

double	ft_pow(double x, unsigned int pow)
{
	double	res;

	res = 1;
	while (pow-- > 0)
		res *= x;
	return (res);
}

//this implemetation only supports positive results, 
//will return 0 for negatives
double	ft_ln(double x)
{
	int		power;
	double	sum;
	double	next_sum;
	int		counter;

	if (x <= 1)
		return (0);
	power = 1;
	sum = 0;
	next_sum = (x - 1) / (x + 1);
	counter = 0;
	while (next_sum > 0.000001 && counter < 100000)
	{
		sum += next_sum;
		power += 2;
		next_sum = ft_pow((x - 1) / (x + 1), power);
		next_sum /= power;
		counter++;
	}
	return (2.0 * sum);
}

int	round_up(double n)
{
	if (n == (float)(int) n)
		return (n);
	return (n + 1);
}

size_t	ft_strlen(const char *str)
{
	unsigned long	counter;

	counter = 0;
	while (str[counter] != 0)
		counter++;
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*ret_cpy;

	ret = malloc(ft_strlen(s1) + 1);
	if (ret == NULL)
		return (ret);
	ret_cpy = ret;
	while (*s1 != 0)
		*(ret++) = *(s1++);
	*ret = 0;
	return (ret_cpy);
}
