/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:14:06 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:14:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_definesize(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		size;
	char	*string;

	nb = (long)n;
	size = ft_definesize(nb);
	string = malloc(sizeof(char) * (size + 1));
	if (string == NULL)
		return (NULL);
	string[size] = '\0';
	if (nb < 0)
	{
		string[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		string[0] = '0';
	while (nb > 0)
	{
		string[size - 1] = (nb % 10) + 48;
		nb /= 10;
		size--;
	}
	return (string);
}
