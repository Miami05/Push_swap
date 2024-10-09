/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elements_stack_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:22:00 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 18:50:43 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * new_max_stack_b - Determines the moves needed to position the maximum value in stack_b
 * @stack: Pointer to the main stacks structure containing stack_b and moves details
 * 
 * This function calculates how many operations are needed to bring the maximum value 
 * of stack_b to the top. It compares the index of the maximum value to the middle of 
 * the stack to decide whether to perform 'rb' (rotate) or 'rrb' (reverse rotate) operations.
 */

void	new_max_stack_b(t_stacks *stack)
{
	int		i;
	int		size;

	if (stack->stack_b->data == stack->values->max_b)
		return ;
	i = find_index_stack_b(stack, stack->values->max_b);
	size = len_of_stack(&stack->stack_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->moves->rrb = size - i;
		else
			stack->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stack->moves->rrb = size - i;
		else
			stack->moves->rb = i;
	}
}

/**
 * new_min_or_max_stack_b - Resets move counters and finds the maximum value in stack_b
 * @stack: Pointer to the main stacks structure containing stack_b and moves details
 * 
 * This function initializes the move counters for rotations and calls the function 
 * to determine the maximum value's position in stack_b.
 */

void	new_min_or_max_stack_b(t_stacks *stack)
{
	stack->moves->rb = 0;
	stack->moves->rrb = 0;
	new_max_stack_b(stack);
}

/**
 * new_num_in_stack_b - Determines the moves needed to position a specified number in stack_b
 * @stack: Pointer to the main stacks structure containing stack_b and moves details
 * @num: The target number to find in stack_b
 * 
 * This function searches for a number smaller than the given number in stack_b, 
 * then calculates how to bring it to the top based on its index relative to the 
 * size of stack_b, similar to the logic in new_max_stack_b.
 */

void	new_num_in_stack_b(t_stacks *stack, int num)
{
	int			i;
	int			size;
	int			nbr;

	stack->moves->rb = 0;
	stack->moves->rrb = 0;
	nbr = search_new_num_in_stack_b(stack, num);
	if (stack->stack_b->data == nbr)
		return ;
	i = find_index_stack_b(stack, nbr);
	size = len_of_stack(&stack->stack_b);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->moves->rrb = size - i;
		else
			stack->moves->rb = i;
	}
	else
	{
		if (i > size / 2)
			stack->moves->rrb = size - i;
		else
			stack->moves->rb = i;
	}
}

/**
 * get_element_top_stack_a - Calculates the moves to bring a specific element to the top of stack_a
 * @stack: Pointer to the main stacks structure containing stack_a and moves details
 * @head: The head node of stack_a
 * @i: The index of the target element in stack_a
 * 
 * This function calculates how many operations are needed to bring a specific element 
 * from stack_a to the top. The calculations are based on the index of the element 
 * and the size of the stack to decide on 'ra' (rotate) or 'rra' (reverse rotate).
 */

void	get_element_top_stack_a(t_stacks *stack, t_node *head, int i)
{
	int			size;

	stack->moves->pb = 1;
	stack->moves->ra = 0;
	stack->moves->rra = 0;
	if (stack->stack_a->data == head->data)
		return ;
	size = len_of_stack(&stack->stack_a);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stack->moves->rra = (size - i);
		else
			stack->moves->ra = i;
	}
	else
	{
		if (i > size / 2)
			stack->moves->rra = (size - i);
		else
			stack->moves->ra = i;
	}
}
