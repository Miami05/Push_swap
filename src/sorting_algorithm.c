/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:20:31 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 19:03:14 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * clear_all - Frees all allocated memory for the stacks.
 * @stack: Pointer to the stacks structure containing stack_a, stack_b,
 *         and other dynamically allocated arrays.
 * 
 * This function clears the linked lists for both stacks and frees any
 * additional memory allocated for moves, values, and cheap arrays.
 */

void	clear_all(t_stacks *stack)
{
	clear_list(&stack->stack_a);
	clear_list(&stack->stack_b);
	free(stack->moves);
	free(stack->values);
	free(stack->cheap);
}

/**
 * push_swap - Main function to sort the stack using push-swap algorithm.
 * @stack: Pointer to the stacks structure containing stack_a and stack_b.
 * 
 * This function implements the push-swap sorting algorithm:
 *  - Checks if the stack is already sorted.
 *  - Sorts the stack based on the number of elements.
 *  - Executes necessary operations to move elements between stacks.
 *  - Finally, cleans up by calling clear_all.
 */

void	push_swap(t_stacks *stack)
{
	if (is_sorted(&stack->stack_a))
		return ;
	else if (len_of_stack(&stack->stack_a) == 2)
	{
		sa(&stack->stack_a);
		return ;
	}
	else if (len_of_stack(&stack->stack_a) == 3)
	{
		sort_three(&stack->stack_a);
		return ;
	}
	else if (len_of_stack(&stack->stack_a) <= 5)
	{
		sort_five(&stack->stack_a, &stack->stack_b);
		return ;
	}
	pb(&stack->stack_b, &stack->stack_a);
	pb(&stack->stack_b, &stack->stack_a);
	cheapest_move(stack);
	sort_three(&stack->stack_a);
	push_to_a(stack);
	clear_all(stack);
}
