/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:47:40 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/09 10:48:51 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_swap *stack_a, t_swap *stack_b, char c)
{
	swap(&stack_a, 'x');
	swap(&stack_b, 'x');
	if (c == 'd')
		write(1, "ss\n", 3);
}

void	rr(t_swap **stack_a, t_swap **stack_b, char c)
{
	rotate(stack_a, 'x');
	rotate(stack_b, 'x');
	if (c == 'd')
		write(1, "rr\n", 3);
}

void	rrr(t_swap **stack_a, t_swap **stack_b, char c)
{
	reverse_rotate(stack_a, 'x');
	reverse_rotate(stack_b, 'x');
	if (c == 'd')
		write(1, "rrr\n", 4);
}
