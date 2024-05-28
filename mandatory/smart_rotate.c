/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:05:08 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/25 11:44:57 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_define_interval(int nb_element)
{
	int	divider;
	int	interval;

	divider = (nb_element / 10) + 15;
	divider = nb_element / divider;
	if (divider == 0)
		divider = 3;
	interval = nb_element / divider;
	return (interval);
}
