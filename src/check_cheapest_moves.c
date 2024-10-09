/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheapest_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:16:27 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 18:40:35 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * check_cost - Calculates and compares the cost of a move sequence
 * @stack: Pointer to the stack structure containing the moves and costs
 * @i: Integer representing the iteration number
 *
 * This function calculates the total cost of the moves currently stored in the
 * `moves` structure. It then compares this cost to the cheapest cost stored in
 * the `cheap` structure. If it's the first iteration or if the new cost is
 * lower than the cheapest found so far, it updates the `cheap` structure to
 * reflect the new cheapest move sequence.
 */

void	check_cost(t_stacks *stack, int i)
{
	stack->moves->cost = stack->moves->pb + stack->moves->ra + stack->moves->rb
		+ stack->moves->rr + stack->moves->rra
		+ stack->moves->rrb + stack->moves->rrr;
	if (i == 1 || stack->cheap->cost > stack->moves->cost)
	{
		stack->cheap->cost = stack->moves->cost;
		stack->cheap->pb = stack->moves->pb;
		stack->cheap->ra = stack->moves->ra;
		stack->cheap->rb = stack->moves->rb;
		stack->cheap->rr = stack->moves->rr;
		stack->cheap->rra = stack->moves->rra;
		stack->cheap->rrb = stack->moves->rrb;
		stack->cheap->rrr = stack->moves->rrr;
	}
}

/**
 * check_double_moves - Reduces redundant moves by combining rotations and reverse rotations
 * @stack: Pointer to the stack structure containing the moves
 *
 * This function optimizes the move sequence by combining rotation operations
 * (`ra` and `rb` into `rr`) and reverse rotation operations (`rra` and `rrb`
 * into `rrr`). If both `ra` and `rb` are non-zero, the number of common rotations
 * is stored in `rr`, and the same logic is applied for reverse rotations.
 */

void	check_double_moves(t_stacks *stack)
{
	stack->moves->rrr = 0;
	stack->moves->rr = 0;
	while (stack->moves->ra != 0 && stack->moves->rb != 0)
	{
		stack->moves->ra--;
		stack->moves->rb--;
		stack->moves->rr++;
	}
	while (stack->moves->rra != 0 && stack->moves->rrb != 0)
	{
		stack->moves->rra--;
		stack->moves->rrb--;
		stack->moves->rrr++;
	}
}

/**
 * check_cheapest_moves - Finds and stores the cheapest move sequence for stack A
 * @stack: Pointer to the stack structure containing the stacks and moves
 *
 * This function iterates through all elements in stack A and calculates the
 * move sequence for each element. It checks whether the element should be
 * moved to the top or the bottom of stack B based on the current state of the
 * stacks. The function also optimizes the moves by reducing redundant
 * rotations and stores the cheapest move sequence for further use.
 */

void	check_cheapest_moves(t_stacks *stack)
{
	int			i;
	int			size;
	t_node		*current;

	i = 0;
	size = len_of_stack(&stack->stack_a);
	current = stack->stack_a;
	while (i++ < size)
	{
		get_element_top_stack_a(stack, current, i - 1);
		if (current->data > stack->values->max_b
			|| current->data < stack->values->min_b)
			new_min_or_max_stack_b(stack);
		else
			new_num_in_stack_b(stack, current->data);
		check_double_moves(stack);
		check_cost(stack, i);
		current = current->next;
	}
}
