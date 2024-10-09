/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 23:16:07 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 21:49:03 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * sa - Swaps the top two elements of stack_a.
 * @stack_a: Pointer to the stack_a linked list.
 * 
 * This function swaps the first two elements of stack_a if the stack
 * contains at least two elements. It updates the pointers accordingly
 * to maintain the integrity of the linked list.
 */

void	sa(t_node **stack_a)
{
	t_node		*first;
	t_node		*second;

	if (*stack_a == NULL || len_of_stack(stack_a) == 1)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*stack_a = second;
	ft_printf("sa\n");
}

/**
 * sb - Swaps the top two elements of stack_b.
 * @stack_b: Pointer to the stack_b linked list.
 * 
 * This function swaps the first two elements of stack_b if the stack
 * contains at least two elements. It updates the pointers accordingly
 * to maintain the integrity of the linked list.
 */

void	sb(t_node **stack_b)
{
	t_node		*first;
	t_node		*second;

	if (*stack_b == NULL || len_of_stack(stack_b) == 1)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	*stack_b = second;
	ft_printf("sb\n");
}

/**
 * ss - Swaps the top two elements of both stack_a and stack_b.
 * @stack_a: Pointer to the stack_a linked list.
 * @stack_b: Pointer to the stack_b linked list.
 * 
 * This function calls sa and sb to swap the top two elements of 
 * both stacks. It prints the operation performed.
 */

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
