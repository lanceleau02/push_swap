/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:50:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/23 11:55:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	char	**parsed_args;
	int		*numbers;
	int		*sort_numbers;
	t_swap	*stack_a;
	t_swap	*stack_b;

	parsed_args = ft_parsing((argc - 1), (argv + 1));
	if (parsed_args == NULL)
		return ;
	numbers = ft_create_numbers(ft_nb_element(parsed_args), parsed_args);
	sort_numbers = ft_create_sort_numbers(ft_nb_element(parsed_args), numbers);
	stack_a = ft_create_list(ft_nb_element(parsed_args), numbers);
	stack_b = NULL;
	ft_indexing(sort_numbers, numbers, ft_nb_element(parsed_args), &stack_a);
	ft_sorting(&stack_a, &stack_b, ft_nb_element(parsed_args));
	ft_free_tab_of_tab(parsed_args);
	free(numbers);
	free(sort_numbers);
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);
}
