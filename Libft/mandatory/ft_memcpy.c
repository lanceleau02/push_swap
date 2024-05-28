/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:23:57 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:26:09 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*copy;
	unsigned char	*original;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	copy = (unsigned char *)dest;
	original = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		copy[i] = original[i];
		i++;
	}
	return (copy);
}
