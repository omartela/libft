/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:19:43 by omartela          #+#    #+#             */
/*   Updated: 2024/04/22 13:40:08 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_digit(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

static char	*number_to_string(char *ptr, int n)
{
	int	i;

	i = count_digit(n);
	ptr = ptr + i;
	*ptr = '\0';
	--ptr;
	if (n == 0)
	{
		*ptr = '0';
		return (ptr);
	}
	while (n > 0)
	{
		*ptr = n % 10 + '0';
		--ptr;
		n = n / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	char	*start_ptr;

	ptr = malloc(sizeof(char) * count_digit(n) + 1);
	if (!ptr)
		return (0);
	start_ptr = ptr;
	number_to_string(ptr, n);
	return (start_ptr);
}
