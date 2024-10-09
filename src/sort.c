/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:29:28 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 18:59:55 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * is_empty - Checks if a stack is empty.
 * @stack: Pointer to the stack to check.
 * 
 * Return: 1 if the stack is empty, otherwise 0.
 */

int	is_empty(t_node **stack)
{
	return (*stack == NULL);
}

/**
 * find_position - Finds the position of a given number in the stack.
 * @stack: Pointer to the head of the stack.
 * @num: The number to find the position of.
 * 
 * Return: The position of num in the stack, or -1 if not found.
 */

int	find_position(t_node **stack, int num)
{
	int		position;
	t_node	*current;

	position = 0;
	current = *stack;
	while (current != NULL)
	{
		if (current->data == num)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

/**
 * find_smallest - Finds the smallest number in the stack.
 * @stack: Pointer to the head of the stack.
 * 
 * Return: The smallest number in the stack.
 */

int	find_smallest(t_node **stack)
{
	int			min;
	t_node		*current;

	min = INT_MAX;
	current = *stack;
	while (current != NULL)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

/**
 * sort_three - Sorts three elements in stack_a.
 * @stack_a: Pointer to the head of stack_a.
 * 
 * This function sorts the top three elements in stack_a using simple rotations.
 */

void	sort_three(t_node **stack_a)
{
	int			a;
	int			b;
	int			c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && a > c)
	{
		ra(stack_a);
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if (b > a && b > c)
	{
		rra(stack_a);
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if (c > a && c > b)
	{
		if (a > b)
			sa(stack_a);
	}
}

/**
 * sort_five - Sorts five elements in stack_a using stack_b as an auxiliary stack.
 * @stack_a: Pointer to the head of stack_a.
 * @stack_b: Pointer to the head of stack_b.
 * 
 * This function sorts the top five elements by moving the smallest elements to stack_b
 * and then sorting the remaining three in stack_a.
 */

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int		min;

	while (len_of_stack(stack_a) > 3)
	{
		min = find_smallest(stack_a);
		while ((*stack_a)->data != min)
		{
			if (find_position(stack_a, min) <= len_of_stack(stack_a) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (!is_empty(stack_b))
	{
		pa(stack_a, stack_b);
	}
}
