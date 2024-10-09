/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_and_min_in_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:56:42 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 18:41:42 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * check_min_in_a - Finds the minimum value in stack A
 * @stack: Pointer to the structure containing all stack information
 * @stack_a: Pointer to the head of stack A
 *
 * This function iterates through all the nodes in stack A and finds the minimum
 * value. It updates the `min_a` field in the `values` structure of the `stack`
 * structure to store the smallest element found in stack A.
 */

void	check_min_in_a(t_stacks *stack, t_node *stack_a)
{
	int		i;
	int		size;

	i = 0;
	size = len_of_stack(&stack_a);
	stack->values->min_a = stack_a->data;
	while (i < size)
	{
		if (stack_a->data < stack->values->min_a)
			stack->values->min_a = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
}

/**
 * check_max_in_a - Finds the maximum value in stack A
 * @stack: Pointer to the structure containing all stack information
 * @stack_a: Pointer to the head of stack A
 *
 * This function iterates through all the nodes in stack A and finds the maximum
 * value. It updates the `max_a` field in the `values` structure of the `stack`
 * structure to store the largest element found in stack A.
 */

void	check_max_in_a(t_stacks *stack, t_node *stack_a)
{
	int			i;
	int			size;

	i = 0;
	size = len_of_stack(&stack_a);
	stack->values->max_a = stack_a->data;
	while (i < size)
	{
		if (stack_a->data > stack->values->max_a)
			stack->values->max_a = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
}

/**
 * check_max_and_min_in_a - Finds both the minimum and maximum values in stack A
 * @stack: Pointer to the structure containing all stack information
 *
 * This function calls both `check_min_in_a` and `check_max_in_a` to find and
 * update the minimum and maximum values in stack A. It ensures that the fields
 * `min_a` and `max_a` in the `values` structure of the `stack` structure are
 * updated with the smallest and largest values in stack A, respectively.
 */

void	check_max_and_min_in_a(t_stacks *stack)
{
	check_min_in_a(stack, stack->stack_a);
	check_max_in_a(stack, stack->stack_a);
}
