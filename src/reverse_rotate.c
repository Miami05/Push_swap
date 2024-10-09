/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 00:20:25 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 21:48:38 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * rrb - Performs a reverse rotate operation on stack_b.
 * @stack_b: Pointer to the head of stack_b.
 * 
 * This function takes the last element of stack_b and moves it to the front. 
 * If stack_b is empty or has only one element, it returns NULL.
 * 
 * Return: Pointer to the updated stack_b.
 */

t_node	**rrb(t_node **stack_b)
{
	t_node		*last;
	t_node		*second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return (NULL);
	last = *stack_b;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	(*stack_b)->prev = last;
	*stack_b = last;
	(*stack_b)->prev = NULL;
	second_last->next = NULL;
	ft_printf("rrb\n");
	return (stack_b);
}

/**
 * rra - Performs a reverse rotate operation on stack_a.
 * @stack_a: Pointer to the head of stack_a.
 * 
 * This function takes the last element of stack_a and moves it to the front.
 * If stack_a is empty or has only one element, it returns NULL.
 * 
 * Return: Pointer to the updated stack_a.
 */

t_node	**rra(t_node **stack_a)
{
	t_node		*last;
	t_node		*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return (NULL);
	last = *stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	(*stack_a)->prev = last;
	*stack_a = last;
	(*stack_a)->prev = NULL;
	second_last->next = NULL;
	ft_printf("rra\n");
	return (stack_a);
}

/**
 * rrr_util - Utility function for reverse rotating stack_b.
 * @stack_b: Pointer to the head of stack_b.
 * @last: Pointer to the last node in stack_b.
 * @second_last: Pointer to the second last node in stack_b.
 * 
 * This function moves the last element of stack_b to the front, similar to rrb.
 */

static void	rrr_util(t_node **stack_b, t_node *last, t_node *second_last)
{
	last = *stack_b;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	(*stack_b)->prev = last;
	*stack_b = last;
	(*stack_b)->prev = NULL;
	second_last->next = NULL;
}

/**
 * rrr - Performs a reverse rotate operation on both stacks.
 * @stack_a: Pointer to the head of stack_a.
 * @stack_b: Pointer to the head of stack_b.
 * 
 * This function moves the last element of both stacks to the front. If both 
 * stacks are empty or have only one element, it does nothing.
 */

void	rrr(t_node **stack_a, t_node **stack_b)
{
	t_node		*last;
	t_node		*second_last;

	if ((*stack_b == NULL || (*stack_b)->next == NULL)
		&& (*stack_a == NULL || (*stack_a)->next == NULL))
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	(*stack_a)->prev = last;
	*stack_a = last;
	(*stack_a)->prev = NULL;
	second_last->next = NULL;
	rrr_util(stack_b, last, second_last);
	ft_printf("rrr\n");
}
