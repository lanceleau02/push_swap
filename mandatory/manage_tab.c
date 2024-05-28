/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:37:04 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/26 19:11:54 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_fill_tab(char **tab, int *nb)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		nb[i] = ft_atoi(tab[i]);
		i++;
	}
	return (nb);
}

static int	*ft_copy_tab(int *src, int *dest, int nb_element)
{
	int	i;

	i = 0;
	while (i < nb_element)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	*ft_create_numbers(int nb_element, char **parsed_args)
{
	int	*numbers;

	numbers = malloc(sizeof(int) * nb_element);
	numbers = ft_fill_tab(parsed_args, numbers);
	return (numbers);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	buff;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				buff = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
}

int	*ft_create_sort_numbers(int nb_element, int *numbers)
{
	int	*sort_numbers;

	sort_numbers = malloc(sizeof(int) * nb_element);
	sort_numbers = ft_copy_tab(numbers, sort_numbers, nb_element);
	ft_sort_int_tab(sort_numbers, nb_element);
	return (sort_numbers);
}
