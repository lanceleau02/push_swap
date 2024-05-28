/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:24:51 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/23 15:08:18 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*ft_create_list(int nb_element, int *numbers)
{
	t_swap	*head;
	t_swap	*current;
	int		i;

	head = malloc(sizeof(t_swap));
	if (head == NULL || numbers == NULL)
		return (NULL);
	current = head;
	current->content = numbers[0];
	i = 1;
	while (i < nb_element)
	{
		current->next = malloc(sizeof(t_swap));
		if (current->next == NULL)
		{
			ft_free_list(&head);
			return (NULL);
		}
		current = current->next;
		current->content = numbers[i];
		i++;
	}
	current->next = NULL;
	return (head);
}

t_swap	*ft_stacklast(t_swap *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
