/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:49:11 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 21:48:50 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * ra - Performs a rotate operation on stack_a.
 * @stack_a: Pointer to the head of stack_a.
 * 
 * This function takes the first element of stack_a and moves it to the back.
 * If stack_a is empty or has only one element, it returns NULL.
 * 
 * Return: Pointer to the updated stack_a.
 */

t_node	**ra(t_node **stack_a)
{
	t_node			*first;
	t_node			*last;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return (NULL);
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf("ra\n");
	return (stack_a);
}

/**
 * rb - Performs a rotate operation on stack_b.
 * @stack_b: Pointer to the head of stack_b.
 * 
 * This function takes the first element of stack_b and moves it to the back.
 * If stack_b is empty or has only one element, it returns NULL.
 * 
 * Return: Pointer to the updated stack_b.
 */

t_node	**rb(t_node **stack_b)
{
	t_node			*first;
	t_node			*last;

	if (*stack_b == NULL || stack_b == NULL || (*stack_b)->next == NULL)
		return (NULL);
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf("rb\n");
	return (stack_b);
}

/**
 * rr_util - Utility function for rotating stack_b.
 * @stack_b: Pointer to the head of stack_b.
 * @first: Pointer to the first node in stack_b.
 * @last: Pointer to the last node in stack_b.
 * 
 * This function moves the first element of stack_b to the back.
 */

static void	rr_util(t_node **stack_b, t_node *first, t_node *last)
{
	first = *stack_b;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

/**
 * rr - Performs a rotate operation on both stacks.
 * @stack_a: Pointer to the head of stack_a.
 * @stack_b: Pointer to the head of stack_b.
 * 
 * This function takes the first element of both stacks and moves it to the back.
 * If either stack is empty or has only one element, it does nothing.
 */

void	rr(t_node **stack_a, t_node **stack_b)
{
	t_node			*first;
	t_node			*last;

	if (*stack_a == NULL || *stack_b == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	rr_util(stack_b, first, last);
	ft_printf("rr\n");
}
