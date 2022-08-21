/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-arpe <mde-arpe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:30:10 by mde-arpe          #+#    #+#             */
/*   Updated: 2022/08/21 21:11:41 by mde-arpe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_bzero(void *s, size_t n)
{
	char	*point;

	point = s;
	while (n > 0)
	{
		*point = 0;
		point++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

//counter acts as strlen
//status 0 if fail
int	ft_atoi(const char *str, int *status)
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
