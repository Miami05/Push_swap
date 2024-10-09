/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:47:59 by ledio             #+#    #+#             */
/*   Updated: 2024/10/08 21:48:22 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * push - Pushes the top node from the source stack to the destination stack.
 * @dest: Pointer to the destination stack.
 * @src: Pointer to the source stack.
 * 
 * This function handles the push operation, linking the nodes correctly 
 * in both stacks.
 */

static void	push(t_node **dest, t_node **src)
{
	t_node	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
