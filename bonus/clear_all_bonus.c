/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:30:33 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 19:05:09 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * clear_all - Clears the linked lists in the stacks and frees resources.
 * @stack: Pointer to the t_stacks structure containing the stacks.
 * 
 * This function clears stack_a and stack_b by calling clear_list for 
 * each. If stack_b is NULL, it avoids calling clear_list for stack_b 
 * to prevent dereferencing a NULL pointer.
 */

void	clear_all(t_stacks *stack)
{
	clear_list(&stack->stack_a);
	if (stack->stack_b != NULL)
		clear_list(&stack->stack_b);
}

/**
 * free_operations - Frees resources and handles errors during operations.
 * @stack: Pointer to the t_stacks structure containing the stacks.
 * @operations: Pointer to the operations string to be freed.
 * 
 * This function calls clear_all to free the linked lists in the stack,
 * then frees the operations string. It subsequently calls error_message 
 * to handle any error reporting.
 */

void	free_operations(t_stacks *stack, char *operations)
{
	clear_all(stack);
	free(operations);
	error_message();
}
