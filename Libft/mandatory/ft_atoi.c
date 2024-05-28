/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:40:13 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 16:45:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	int				minus;
	long			nb;

	i = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	minus = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i++;
	}
	nb = 0;
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]) == 1)
	{
		if (nb * minus > 2147483647)
			return (-1);
		if (nb * minus < -2147483648)
			return (0);
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (minus * nb);
}
