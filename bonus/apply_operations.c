/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:31:33 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/28 11:11:53 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bad_input(void)
{
	get_next_line(-1);
	write(2, "Error\n", 6);
	return (1);
}

static int	apply_operations(t_swap **stack_a, t_swap **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(stack_a, 'x');
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(stack_b, 'x');
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(*stack_a, *stack_b, 'x');
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push(stack_b, stack_a, 'x');
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(stack_a, stack_b, 'x');
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(stack_a, 'x');
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(stack_b, 'x');
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 'x');
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(stack_a, 'x');
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(stack_b, 'x');
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 'x');
	else
		return (bad_input());
	return (0);
}

void	manual_sort(t_swap **stack_a, t_swap **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (apply_operations(stack_a, stack_b, line) == 1)
		{
			free(line);
			line = NULL;
			return ;
		}
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	if (ft_verify_sort(*stack_a, *stack_b) == 0 \
		&& ft_define_nb_element_stack(*stack_a) > 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
