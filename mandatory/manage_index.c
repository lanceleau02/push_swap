/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:45:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/23 11:54:58 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_index(t_swap *stack)
{
	t_swap	*head;
	int		min;
	int		i;
	int		j;

	head = stack;
	min = stack->content;
	i = 0;
	j = 0;
	while (stack != NULL)
	{
		if (min > stack->content)
		{
			min = stack->content;
			j = i;
		}
		i++;
		stack = stack->next;
	}
	stack = head;
	return (j);
}

int	ft_find_max_index(t_swap *stack)
{
	t_swap	*head;
	int		max;
	int		i;
	int		j;

	head = stack;
	max = stack->content;
	i = 0;
	j = 0;
	while (stack != NULL)
	{
		if (max < stack->content)
		{
			max = stack->content;
			j = i;
		}
		i++;
		stack = stack->next;
	}
	stack = head;
	return (j);
}

void	ft_indexing(int *sort, int *unsort, int nb_element, t_swap **stack_a)
{
	t_swap	*head;
	int		i;
	int		j;

	i = 0;
	head = *stack_a;
	while (i < nb_element)
	{
		j = 0;
		while (j < nb_element)
		{
			if (unsort[i] == sort[j])
			{
				(*stack_a)->index = j;
				*stack_a = (*stack_a)->next;
			}
			j++;
		}
		i++;
	}
	*stack_a = head;
}

int	ft_find_element_unsort_stack(t_swap *stack, int unsort_index)
{
	int	i;

	i = 0;
	while (i != unsort_index)
	{
		stack = stack->next;
		i++;
	}
	return (stack->index);
}
