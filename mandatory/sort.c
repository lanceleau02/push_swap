/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:20:03 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/26 13:51:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_swap **stack_a, t_swap **stack_b, int nb_element)
{
	if (ft_verify_sort(*stack_a, *stack_b) == 0 || nb_element == 1)
		return ;
	else if (nb_element == 2)
		ft_sort_two(stack_a);
	else if (nb_element == 3)
		ft_sort_three(stack_a);
	else if (nb_element == 4)
		ft_sort_four(stack_a, stack_b, nb_element);
	else if (nb_element == 5)
		ft_sort_five(stack_a, stack_b, nb_element);
	else
		ft_sort(stack_a, stack_b, nb_element, 0);
}
