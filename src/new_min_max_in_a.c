/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_min_max_in_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:32:05 by ledio             #+#    #+#             */
/*   Updated: 2024/10/09 13:30:26 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * max_move_stack - 
 * Executes the moves to bring the maximum number from stack_b to stack_a.
 * @stack: Pointer to the main stacks structure containing stack_a and stack_b.
 * 
 * This function applies the calculated rotation moves to stack_a, followed by 
 * moving the top element of stack_b to stack_a, and then performs an additional 
 * rotation on stack_a.
 */

void	max_move_stack(t_stacks *stack)
{
	while (stack->moves->ra-- > 0)
		ra(&stack->stack_a);
	while (stack->moves->rra-- > 0)
		rra(&stack->stack_a);
	pa(&stack->stack_a, &stack->stack_b);
	ra(&stack->stack_a);
}

/**
 * check_last - Returns the last node of stack_a.
 * @stack_a: Pointer to the head node of stack_a.
 * 
 * This function traverses stack_a to find
 * and return the last node in the stack.
 * It is used to determine the current position
 * of the maximum element in stack_a.
 * 
 * Return: Pointer to the last node of stack_a.
 */

t_node	*check_last(t_node *stack_a)
{
	t_node	*current;

	current = stack_a;
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

/**
 * new_max_num_in_a - Prepares to move the maximum number in stack_a to the top.
 * @stack: 
 * Pointer to the main stacks structure containing stack_a and its moves.
 * 
 * This function calculates how to bring the 
 * maximum number in stack_a to the top, 
 * considering whether to use a rotate
 * or reverse rotate based on the index of the maximum value.
 */

void	new_max_num_in_a(t_stacks *stack)
{
	int			index;
	int			size;

	stack->moves->ra = 0;
	stack->moves->rra = 0;
	if (check_last(stack->stack_a)->data != stack->values->max_a)
	{
		index = find_index_stack_a(stack, stack->values->max_a);
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
	max_move_stack(stack);
}

/**
 * min_move_stack -
 * Executes the moves to bring the minimum number from stack_b to stack_a.
 * @stack: Pointer to the main stacks structure
 * containing stack_a and stack_b.
 * 
 * This function performs the required rotatio
 *  moves and transfers the top element from stack_b to stack_a.
 */

void	min_move_stack(t_stacks *stack)
{
	while (stack->moves->ra-- > 0)
		ra(&stack->stack_a);
	while (stack->moves->rra-- > 0)
		rra(&stack->stack_a);
	pa(&stack->stack_a, &stack->stack_b);
}

/**
 * new_min_num_in_a -
 * Prepares to move the minimum number in
 * stack_a to the top.
 * @stack: Pointer to the main stacks structure
 * containing stack_a and its moves.
 * 
 * This function calculates how to bring
 * the minimum number in stack_a to the top, 
 * considering whether to use a rotate or
 * reverse rotate based on the index of the minimum value.
 */

void	new_min_num_in_a(t_stacks *stack)
{
	int			index;
	int			size;

	stack->moves->ra = 0;
	stack->moves->rra = 0;
	if (stack->stack_a->data != stack->values->min_a)
	{
		size = len_of_stack(&stack->stack_a);
		index = find_index_stack_a(stack, stack->values->min_a);
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
	min_move_stack(stack);
}
