/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:19:16 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/26 14:58:33 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_swap **stack, char c)
{
	int		tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	push(t_swap **from_stack, t_swap **to_stack, char c)
{
	t_swap	*first;
	t_swap	*tmp;

	if (ft_define_nb_element_stack(*from_stack) < 1)
		return ;
	if (*from_stack != NULL)
	{
		first = *from_stack;
		*from_stack = (*from_stack)->next;
	}
	if (*to_stack != NULL)
	{
		tmp = *to_stack;
		first->next = tmp;
		*to_stack = first;
	}
	else
	{
		*to_stack = first;
		first->next = NULL;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_swap **stack, char c)
{
	t_swap	*tmp;

	if ((*stack) == NULL)
		return ;
	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_stacklast(*stack)->next = tmp;
		tmp->next = NULL;
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_swap **stack, char c)
{
	t_swap	*prev;
	t_swap	*last;

	if ((*stack) == NULL)
		return ;
	if ((*stack)->next != NULL)
	{
		prev = *stack;
		last = (*stack)->next;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		prev->next = NULL;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
