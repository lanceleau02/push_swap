/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:48:11 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/27 15:47:12 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verify_sort(t_swap *stack_a, t_swap *stack_b)
{
	if (ft_define_nb_element_stack(stack_b) > 0)
		return (1);
	while (stack_a->next != NULL)
	{
		if (stack_a->content < stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (1);
	}
	return (0);
}
