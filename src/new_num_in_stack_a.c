/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_num_in_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 22:01:22 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 18:53:51 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * search_new_num - Searches for the next number in stack_a that is larger than the current number.
 * @stack: Pointer to the main stacks structure containing stack_a.
 * @number: The current number to be incremented and searched.
 * 
 * This function increments the number and searches stack_a for that number, 
 * returning it once found.
 * 
 * Return: The next number found in stack_a.
 */

int	search_new_num(t_stacks *stack, int number)
{
	int			i;
	int			size;
	int			flag;
	t_node		*current;

	flag = 0;
	current = stack->stack_a;
	size = len_of_stack(&stack->stack_a);
	while (flag == 0)
	{
		i = 0;
		number++;
		current = stack->stack_a;
		while (i++ < size)
		{
			if (current->data == number)
				flag = 1;
			current = current->next;
		}
	}
	return (number);
}

/**
 * move_elem_stack_a - Executes the moves to bring the element from stack_b to stack_a.
 * @stack: Pointer to the main stacks structure containing stack_a and stack_b.
 * 
 * This function applies the calculated rotation moves to stack_a, 
 * followed by moving the top element of stack_b to stack_a.
 */

void	move_elem_stack_a(t_stacks *stack)
{
	while (stack->moves->ra-- > 0)
		ra(&stack->stack_a);
	while (stack->moves->rra-- > 0)
		rra(&stack->stack_a);
	pa(&stack->stack_a, &stack->stack_b);
}

/**
 * new_num_in_stack_a - Prepares to move a new number from stack_b to stack_a.
 * @stack: Pointer to the main stacks structure containing stack_a and stack_b.
 * @stack_b: Pointer to the head node of stack_b.
 * 
 * This function calculates how to bring a newly identified number from stack_b 
 * to stack_a, considering the necessary rotations based on the index of that number.
 */

void	new_num_in_stack_a(t_stacks *stack, t_node *stack_b)
{
	int			index;
	int			size;

	stack->moves->ra = 0;
	stack->moves->rra = 0;
	if (stack->stack_a->data != search_new_num(stack, stack_b->data))
	{
		index = find_index_stack_a(stack, search_new_num(stack, stack_b->data));
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
	move_elem_stack_a(stack);
}
