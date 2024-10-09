/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:17:06 by ledio             #+#    #+#             */
/*   Updated: 2024/10/09 13:23:21 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * create_node - Allocates memory for a new node and initializes it
 * @data: The data to store in the new node
 * 
 * This function creates a new doubly linked list node. It allocates memory
 * for the node and sets its data to the given value. The `next` and `prev`
 * pointers of the node are initialized to NULL.
 * 
 * Return: Pointer to the newly created node, or NULL if memory allocation fails.
 */

t_node	*create_node(int data)
{
	t_node		*current;

	current = (t_node *)malloc(sizeof(t_node));
	if (!current)
		return (NULL);
	current->data = data;
	current->next = NULL;
	current->prev = NULL;
	return (current);
}

/**
 * add_node - Adds a new node with the given data to the end of the list
 * @head: Double pointer to the head of the list
 * @data: The data to store in the new node
 * 
 * This function creates a new node using the `create_node` function and adds it
 * to the end of the doubly linked list. If the list is empty,
 * the new node becomes the head.
 * Otherwise, the function traverses the list to the end and appends the
 * new node there.
 * 
 * Return: Pointer to the head of the list (unchanged),
 * or NULL if memory allocation fails.
 */

t_node	*add_node(t_node **head, int data)
{
	t_node		*current;
	t_node		*temp;

	current = create_node(data);
	if (!current)
		return (*head);
	if (*head == NULL)
		*head = current;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = current;
		current->prev = temp;
	}
	return (*head);
}

/**
 * clear_list - Frees all nodes in the linked list
 * @head: Double pointer to the head of the list
 * 
 * This function frees all the nodes in a doubly linked list. It traverses
 * the list, freeing each node, and sets the head pointer to NULL to
 * indicate that the list is now empty.
 * 
 * Return: NULL (for convenience when clearing a list in assignments)
 */

void	*clear_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (head == NULL)
		return (NULL);
	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
	return (NULL);
}
