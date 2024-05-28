/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:43:34 by laprieur          #+#    #+#             */
/*   Updated: 2023/06/18 17:44:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	else if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] != '\0' && i < len)
		i++;
	new_s = malloc(sizeof(char) * (i + 1));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		new_s[i] = s[start];
		i++;
		start++;
	}
	new_s[i] = '\0';
	return (new_s);
}
