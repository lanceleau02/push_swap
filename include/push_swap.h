/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:20:52 by laprieur          #+#    #+#             */
/*   Updated: 2024/05/28 11:11:07 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"
# include <stdlib.h>

/* ************************************************************************** */
/*                                 MANDATORY                                  */
/* ************************************************************************** */

typedef struct s_swap
{
	int				content;
	int				index;
	struct s_swap	*next;
}	t_swap;

int		*ft_create_numbers(int nb_element, char **parsed_args);
int		*ft_create_sort_numbers(int nb_element, int *numbers);
int		ft_check_duplicates(char **tab);
int		ft_check_full_space(char *str);
int		ft_check_int_size(char **tab);
int		ft_check_type(char *str);
int		ft_define_interval(int nb_element);
int		ft_define_nb_element_stack(t_swap *stack);
int		ft_error(void);
int		ft_find_element_in_interval(int nb_element, t_swap **stacki);
int		ft_find_element_unsort_stack(t_swap *stack, int index);
int		ft_find_max_index(t_swap *stack);
int		ft_find_min_index(t_swap *stack);
int		ft_nb_element(char **parsed_args);
int		ft_verify_sort(t_swap *stack_a, t_swap *stack_b);
char	**ft_parsing(int argc, char **argv);
void	ft_final_part(t_swap **stack_a, t_swap **stack_b);
void	ft_free_list(t_swap **stack);
void	ft_free_tab_of_tab(char **tab);
void	ft_indexing(int *sort, int *unsort, int nb_element, t_swap **stack_a);
void	ft_sort(t_swap **stack_a, t_swap **stack_b, int nb_element, int i);
void	ft_sort_five(t_swap **stack_a, t_swap **stack_b, int nb_element);
void	ft_sort_four(t_swap **stack_a, t_swap **stack_b, int nb_element);
void	ft_sort_three(t_swap **stack_a);
void	ft_sort_two(t_swap **stack_a);
void	ft_sorting(t_swap **stack_a, t_swap **stack_b, int nb_element);
void	push(t_swap **from_stack, t_swap **to_stack, char c);
void	push_swap(int argc, char **argv);
void	reverse_rotate(t_swap **stack, char c);
void	rotate(t_swap **stack, char c);
void	rr(t_swap **stack_a, t_swap **stack_b, char c);
void	rrr(t_swap **stack_a, t_swap **stack_b, char c);
void	ss(t_swap *stack_a, t_swap *stack_b, char c);
void	swap(t_swap **stack, char c);
t_swap	*ft_create_list(int nb_element, int *numbers);
t_swap	*ft_stacklast(t_swap *stack);

/* ************************************************************************** */
/*                                   BONUS                                    */
/* ************************************************************************** */

void	checker(int argc, char **argv);
void	ft_print_all_list(t_swap *stacK_a, t_swap *stack_b);
void	manual_sort(t_swap **stack_a, t_swap **stack_b);

#endif
