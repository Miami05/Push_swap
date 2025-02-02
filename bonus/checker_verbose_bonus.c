/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_verbose_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:17:34 by ledio             #+#    #+#             */
/*   Updated: 2025/01/14 21:48:50 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * print_height - Prints elements from both stack_a and stack_b up to max_count.
 * @stack: Pointer to the t_stacks structure containing the stacks.
 * @max_count: Maximum number of lines to print (height of the taller stack).
 * @current_a:
 * Pointer to the current node in stack_a (starts as NULL, initialized inside).
 *
 * This function prints both stacks side by side. If one stack is shorter,
 * empty space is printed for missing elements.
 */

void	print_height(t_stacks *stack, int max_count, t_node *current_a)
{
	t_node			*current_b;
	int				i;

	i = 0;
	current_a = stack->stack_a;
	current_b = stack->stack_b;
	while (i < max_count)
	{
		if (current_a != NULL)
		{
			ft_printf("%d\t\t", current_a->data);
			current_a = current_a->next;
		}
		else
			ft_printf(" \t\t");
		if (current_b != NULL)
		{
			ft_printf("%d\n", current_b->data);
			current_b = current_b->next;
		}
		else
			ft_printf("\n");
		i++;
	}
	ft_printf("-------------\n");
}

/**
 * print_stacks - Prints the current state of stack_a and stack_b.
 * @stack: Pointer to the t_stacks structure containing the stacks.
 *
 * This function displays the elements in stack_a and stack_b in a
 * visually understandable format.
 */

void	print_stack(t_stacks *stack)
{
	t_node				*current_a;
	int					a_count;
	int					b_count;
	int					max_count;

	current_a = NULL;
	a_count = len_of_stack(&stack->stack_a);
	b_count = len_of_stack(&stack->stack_b);
	max_count = a_count;
	if (b_count > max_count)
		max_count = b_count;
	ft_printf("Stack A\t\tStack B\n");
	print_height(stack, max_count, current_a);
}

/**
 * check_visual -
 * Checks if the '-v' flag is passed in the arguments and adjusts argc.
 * @argc: Pointer to the argument count (will be modified if '-v' is found).
 * @argv: Argument vector (array of strings).
 * @visual: Visual flag (0 by default, set to 1 if '-v' is found).
 *
 * This function scans the arguments for the '-v' flag.
 * If found, it removes the flag from argv,
 * adjusts argc, and sets visual to 1.
 *
 * Return: 1 if '-v' flag is found, 0 otherwise.
 */

int	check_visual(int *argc, char **argv, int visual)
{
	int				i;
	int				j;

	if (argc == NULL || argv == NULL || *argc == 0)
		return (0);
	i = 1;
	visual = 0;
	while (i < *argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
		{
			visual = 1;
			j = i;
			while (j < *argc)
			{
				argv[j] = argv[j + 1];
				j++;
			}
			(*argc)--;
		}
		i++;
	}
	return (visual);
}
