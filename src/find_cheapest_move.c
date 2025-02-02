/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:18:36 by ledio             #+#    #+#             */
/*   Updated: 2025/01/14 21:56:19 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * do_cheapest_move -
 * Executes the series of moves stored in the cheapest move structure
 * @stack: Pointer to the main stacks structure containing stack_a,
 * stack_b, and move details
 *
 * This function performs the cheapest moves calculated earlier in the program.
 * It reduces the counter in the `cheap` structure as
 * it executes each corresponding operation (e.g.,
 * ra, rb, rra, rrb, etc.).
 * The moves are executed in a specific order to transfer elements
 * between stack_a and stack_b efficiently.
 */

void	do_cheapest_move(t_stacks *stack)
{
	while (stack->cheap->ra-- > 0)
		ra(&stack->stack_a);
	while (stack->cheap->rb-- > 0)
		rb(&stack->stack_b);
	while (stack->cheap->rr-- > 0)
		rr(&stack->stack_a, &stack->stack_b);
	while (stack->cheap->rra-- > 0)
		rra(&stack->stack_a);
	while (stack->cheap->rrb-- > 0)
		rrb(&stack->stack_b);
	while (stack->cheap->rrr-- > 0)
		rrr(&stack->stack_a, &stack->stack_b);
	while (stack->cheap->pb-- > 0)
		pb(&stack->stack_b, &stack->stack_a);
}

/**
 * cheapest_move - Finds and executes the cheapest move from stack_a to stack_b
 * @stack: Pointer to the main stacks structure containing
 * stack_a, stack_b, and move details
 *
 * This function allocates memory for moves,
 * cheapest moves, and values structures.
 * It then repeatedly calculates the cheapest moves, executes them,
 * and updates the stack
 * until only three elements are left in stack_a.
 * It calls helper functions to perform
 * various operations like checking max/min values and calculating moves.
 */

void	cheapest_move(t_stacks *stack)
{
	t_moves		*moves;
	t_cheap		*cheap;
	t_values	*values;

	moves = ft_calloc(1, sizeof(t_moves));
	stack->moves = moves;
	cheap = ft_calloc (1, sizeof(t_cheap));
	stack->cheap = cheap;
	values = ft_calloc(1, sizeof(t_values));
	stack->values = values;
	while (len_of_stack(&stack->stack_a) > 3)
	{
		check_max_and_min_in_b(stack);
		check_cheapest_moves(stack);
		do_cheapest_move(stack);
	}
}

/**
 * search_new_num_in_stack_b -
 * Finds the closest number in stack_b smaller than the input number
 * @stack: Pointer to the main stacks structure containing stack_b
 * @num: The target number to find in stack_b
 *
 * This function searches for the number closest
 * to but smaller than the input number in stack_b.
 * It decreases the number step by step and scans stack_b
 * until the number is found. If the number is found,
 * it returns that number.
 *
 * Return: The closest smaller number found in stack_b.
 */

int	search_new_num_in_stack_b(t_stacks *stack, int num)
{
	int			i;
	int			size;
	int			flag;
	t_node		*current;

	i = 0;
	flag = 0;
	current = stack->stack_b;
	size = len_of_stack(&stack->stack_b);
	while (flag == 0)
	{
		i = 0;
		num--;
		current = stack->stack_b;
		while (i++ < size)
		{
			if (current->data == num)
				flag = 1;
			current = current->next;
		}
	}
	return (num);
}

/**
 * find_index_stack_b - Finds the index of the target value in stack_b
 * @stack: Pointer to the main stacks structure containing stack_b
 * @target_value: The value to search for in stack_b
 *
 * This function searches for a
 * specific target value in stack_b and returns the index
 * (position) of that value.
 * It traverses stack_b from the beginning, checking each node's
 * data until it finds the target value.
 *
 * Return: The index of the target value in stack_b.
 */

int	find_index_stack_b(t_stacks *stack, int target_value)
{
	int			i;
	int			size;
	t_node		*current;

	i = 0;
	size = len_of_stack(&stack->stack_b);
	current = stack->stack_b;
	while (i < size)
	{
		if (current->data == target_value)
			break ;
		current = current->next;
		i++;
	}
	return (i);
}
