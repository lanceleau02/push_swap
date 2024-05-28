/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:00:53 by laprieur          #+#    #+#             */
/*   Updated: 2023/07/14 10:18:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memblock;

	if ((int)nmemb < 0 && (int)size < 0)
		return (NULL);
	memblock = malloc(sizeof(char) * (nmemb * size));
	if (memblock == NULL)
		return (NULL);
	ft_bzero(memblock, (nmemb * size));
	return (memblock);
}
