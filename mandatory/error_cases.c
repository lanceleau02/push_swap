/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:05:09 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/27 16:35:39 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_full_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = 0;
	while (str[j])
		j++;
	if (i == j)
		return (1);
	return (0);
}

int	ft_check_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
			return (1);
		if (ft_isdigit(str[i]) == 0 && str[i] != ' '
			&& str[i] != '-' && str[i] != '+')
			return (1);
		if (ft_isdigit(str[i]) == 1
			&& (str[i + 1] == '+' || str[i + 1] == '-'))
			return (1);
		if ((str[i] == '+' && ft_isdigit(str[i + 1]) != 1)
			|| (str[i] == '-' && ft_isdigit(str[i + 1]) != 1))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int_size(char **tab)
{
	int			i;
	const char	**new_tab;

	i = 0;
	new_tab = (const char **)tab;
	while (new_tab[i])
	{
		if (ft_atol(new_tab[i]) > 2147483647
			|| ft_atol(new_tab[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_duplicates(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
