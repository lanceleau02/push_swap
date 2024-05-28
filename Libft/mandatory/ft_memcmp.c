/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:23:04 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:23:47 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*firstblock;
	unsigned char	*secondblock;
	size_t			i;

	firstblock = (unsigned char *)s1;
	secondblock = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (firstblock[i] != secondblock[i])
			return (firstblock[i] - secondblock[i]);
		i++;
	}
	return (0);
}
