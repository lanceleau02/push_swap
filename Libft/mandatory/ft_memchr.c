/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:22:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:22:20 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*memblock;
	size_t			i;

	memblock = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (memblock[i] == (unsigned char)c)
			return (&memblock[i]);
		i++;
	}
	return (NULL);
}
