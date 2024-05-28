/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:45:11 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/20 18:25:21 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_swap **stack_a)
{
	if ((*stack_a)->content < (*stack_a)->next->content)
		return ;
	swap(stack_a, 'a');
}

void	ft_sort_three(t_swap **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		rotate(stack_a, 'a');
	else if ((*stack_a)->next->content > (*stack_a)->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		reverse_rotate(stack_a, 'a');
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 'a');
}

void	ft_sort_four(t_swap **stack_a, t_swap **stack_b, int nb_element)
{
	int	min_index;
	int	i;

	min_index = ft_find_min_index(*stack_a);
	i = 0;
	if (min_index == nb_element - 1)
		reverse_rotate(stack_a, 'a');
	else if (min_index != nb_element)
	{
		while (i < min_index)
		{
			rotate(stack_a, 'a');
			i++;
		}
	}
	push(stack_a, stack_b, 'b');
	ft_sort_three(stack_a);
	push(stack_b, stack_a, 'a');
}

void	ft_sort_five(t_swap **stack_a, t_swap **stack_b, int nb_element)
{
	int	min_index;
	int	i;

	min_index = ft_find_min_index(*stack_a);
	i = 0;
	if (min_index == nb_element - 1)
		reverse_rotate(stack_a, 'a');
	else if (min_index != nb_element)
	{
		while (i < min_index)
		{
			rotate(stack_a, 'a');
			i++;
		}
	}
	push(stack_a, stack_b, 'b');
	ft_sort_four(stack_a, stack_b, nb_element - 1);
	push(stack_b, stack_a, 'a');
}

void	ft_sort(t_swap **stack_a, t_swap **stack_b, int nb_element, int i)
{
	int		interval;
	int		nb_element_a;
	int		pivot;

	interval = ft_define_interval(nb_element);
	nb_element_a = ft_define_nb_element_stack(*stack_a);
	pivot = nb_element / interval;
	while (interval < nb_element_a)
	{
		while (i < interval)
		{
			if ((*stack_a)->index < interval)
			{
				push(stack_a, stack_b, 'b');
				if ((*stack_b)->index > (interval - (nb_element / (2 * pivot)))
					&& ft_define_nb_element_stack(*stack_b) != 1)
					rotate(stack_b, 'b');
				i++;
			}
			else
				rotate(stack_a, 'a');
		}
		interval += ft_define_interval(nb_element_a);
	}
	ft_final_part(stack_a, stack_b);
}
