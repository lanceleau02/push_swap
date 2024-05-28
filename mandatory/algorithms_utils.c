/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:06:01 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/26 13:33:23 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_define_nb_element_stack(t_swap *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static void	smart_rotate(t_swap **stack_a, t_swap **stack_b, int sort_max)
{
	while ((*stack_b)->index != sort_max)
	{
		if ((*stack_b)->index == sort_max - 1)
			push(stack_b, stack_a, 'a');
		else
			rotate(stack_b, 'b');
	}
}

static void	smart_rev_rotate(t_swap **stack_a, t_swap **stack_b, int sort_max)
{
	while ((*stack_b)->index != sort_max)
	{
		if ((*stack_b)->index == sort_max - 1)
			push(stack_b, stack_a, 'a');
		else
			reverse_rotate(stack_b, 'b');
	}
}

static void	ft_push_to_stack_a(t_swap **stack_a, t_swap **stack_b)
{
	int	unsort_max;
	int	sort_max;
	int	nb_element_b;

	while (*stack_b != NULL)
	{
		nb_element_b = ft_define_nb_element_stack(*stack_b);
		unsort_max = ft_find_max_index(*stack_b);
		sort_max = ft_find_element_unsort_stack(*stack_b, unsort_max);
		if (unsort_max <= (nb_element_b / 2))
			smart_rotate(stack_a, stack_b, sort_max);
		else
			smart_rev_rotate(stack_a, stack_b, sort_max);
		push(stack_b, stack_a, 'a');
		if (*stack_a != NULL && (*stack_a)->next != NULL)
			ft_sort_two(stack_a);
	}
}

void	ft_final_part(t_swap **stack_a, t_swap **stack_b)
{
	while (ft_define_nb_element_stack(*stack_a) > 0)
		push(stack_a, stack_b, 'b');
	ft_push_to_stack_a(stack_a, stack_b);
}
