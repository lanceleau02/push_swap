/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:26:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:27:25 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*copy;
	unsigned char	*original;
	int				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	copy = (unsigned char *)dest;
	original = (unsigned char *)src;
	if (copy < original)
		ft_memcpy(copy, original, n);
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			copy[i] = original[i];
			i--;
		}
	}
	return (copy);
}
