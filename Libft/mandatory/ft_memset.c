/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:27:37 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:27:49 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*area;

	area = (unsigned char *)s;
	while (n != 0)
	{
		area[n - 1] = c;
		n--;
	}
	return (s);
}
