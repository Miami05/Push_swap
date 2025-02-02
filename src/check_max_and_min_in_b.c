/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_and_min_in_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:26:41 by ledio             #+#    #+#             */
/*   Updated: 2025/02/02 16:01:27 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * check_min_in_b - Finds the minimum value in stack B
 * @stack: Pointer to the structure containing all stack information
 * @stack_b: Pointer to the head of stack B
 *
 * This function iterates through all the nodes in stack B and finds the minimum
 * value. It updates the `min_b` field in the `values` structure of the `stack`
 * s
*/

void	check_min(t_stacks *stack, t_node *stack_b)
{
	int			i;
	int			size;

	i = 0;
	size = len_of_stack(&stack_b);
	stack->values->min_b = stack_b->data;
	while (i < size)
	{
		if (stack->values->min_b > stack_b->data)
			stack->values->min_b = stack_b->data;
		stack_b = stack_b->next;
		i++;
	}
}

/**
 * check_max_in_a - Finds the maximum value in stack B
 * @stack: Pointer to the structure containing all stack information
 * @stack_b: Pointer to the head of stack B
 *
 * This function iterates through all the nodes in stack B and finds the maximum
 * value. It updates the `max_b` field in the `values` structure of the `stack`
 * structure to store the largest element found in stack B.
 */

void	check_max(t_stacks *stack, t_node *stack_b)
{
	int			i;
	int			size;

	i = 0;
	size = len_of_stack(&stack_b);
	stack->values->max_b = stack_b->data;
	while (i < size)
	{
		if (stack->values->max_b < stack_b->data)
			stack->values->max_b = stack_b->data;
		stack_b = stack_b->next;
		i++;
	}
}

/**
 * check_max_and_min_in_b - Finds both the minimum and maximum values in stack B
 * @stack: Pointer to the structure containing all stack information
 *
 * This function calls both `check_min_in_b` and `check_max_in_b` to find and
 * update the minimum and maximum values in stack B. It ensures that the fields
 * `min_b` and `max_b` in the `values` structure of the `stack` structure are
 * updated with the smallest and largest values in stack B, respectively.
 */

void	check_max_and_min_in_b(t_stacks *stack)
{
	if (stack->stack_b != NULL)
	{
		check_min(stack, stack->stack_b);
		check_max(stack, stack->stack_b);
	}
}
