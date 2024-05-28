/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:42:47 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/28 11:11:47 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(int argc, char **argv)
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
	manual_sort(&stack_a, &stack_b);
	ft_free_tab_of_tab(parsed_args);
	free(numbers);
	free(sort_numbers);
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);
}
