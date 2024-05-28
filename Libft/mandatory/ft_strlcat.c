/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:34:24 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:34:44 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dst >= size)
		return (size_src + size);
	i = 0;
	while (src[i] != '\0' && (size_dst + i) < (size - 1))
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
