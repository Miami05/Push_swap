/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:48:40 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 18:56:13 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * find_index_stack_a - Finds the index of a number in stack_a.
 * @stack: Pointer to the main stacks structure containing stack_a.
 * @nbr: The number whose index is to be found in stack_a.
 * 
 * This function iterates through stack_a to find the index of the specified 
 * number.
 * 
 * Return: The index of the number in stack_a.
 */

int	find_index_stack_a(t_stacks *stack, int nbr)
{
	int			i;
	int			size;
	t_node		*current;

	i = 0;
	size = len_of_stack(&stack->stack_a);
	current = stack->stack_a;
	while (i < size)
	{
		if (current->data == nbr)
			break ;
		current = current->next;
		i++;
	}
	return (i);
}

/**
 * move_stack - Executes the rotation moves on stack_a.
 * @stack: Pointer to the main stacks structure containing stack_a.
 * 
 * This function performs the required number of rotations and reverse rotations 
 * on stack_a based on the values in the moves structure.
 */

void	move_stack(t_stacks *stack)
{
	while (stack->moves->ra-- > 0)
		ra(&stack->stack_a);
	while (stack->moves->rra-- > 0)
		rra(&stack->stack_a);
}

/**
 * reorder_the_stack - Reorders stack_a to bring the minimum number to the top.
 * @stack: Pointer to the main stacks structure containing stack_a.
 * 
 * This function calculates the necessary moves to bring the minimum value 
 * in stack_a to the top and executes those moves.
 */

void	reorder_the_stack(t_stacks *stack)
{
	int			index;
	int			size;

	stack->moves->ra = 0;
	stack->moves->rra = 0;
	if (stack->stack_a->data != stack->values->min_a)
	{
		index = find_index_stack_a(stack, stack->values->min_a);
		size = len_of_stack(&stack->stack_a);
		if (size % 2 == 0)
		{
			if (index + 1 > size / 2)
				stack->moves->rra = size - index;
			else
				stack->moves->ra = index;
		}
		else
		{
			if (index > size / 2)
				stack->moves->rra = size - index;
			else
				stack->moves->ra = index;
		}
	}
	move_stack(stack);
}

/**
 * push_to_a - Moves elements from stack_b to stack_a based on conditions.
 * @stack: Pointer to the main stacks structure containing stack_a and stack_b.
 * 
 * This function checks the values in stack_b and determines where to place 
 * them in stack_a based on their comparison with the min and max values.
 */

void	push_to_a(t_stacks *stack)
{
	while (stack->stack_b != NULL)
	{
		check_max_and_min_in_a(stack);
		if (stack->stack_b->data < stack->values->min_a)
			new_min_num_in_a(stack);
		else if (stack->stack_b->data > stack->values->max_a)
			new_max_num_in_a(stack);
		else
			new_num_in_stack_a(stack, stack->stack_b);
	}
	check_max_and_min_in_a(stack);
	reorder_the_stack(stack);
}
