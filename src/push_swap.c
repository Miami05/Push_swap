/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 01:07:14 by ledio             #+#    #+#             */
/*   Updated: 2025/01/09 18:50:54 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "errors.h"

/**
 * free_split - Frees the memory allocated for a split string array.
 * @split_argv: Pointer to the split string array to be freed.
 *
 * This function iterates through the split string array and frees each
 * allocated string, followed by freeing the array itself.
 */

void	free_split(char **split_argv)
{
	int			j;

	j = 0;
	while (split_argv[j] != NULL)
	{
		free(split_argv[j]);
		j++;
	}
	free(split_argv);
}

/**
 * parse_arguments - Parses command line arguments and populates stack_a.
 * @argc: Argument count from the command line.
 * @argv: Argument values from the command line.
 * @stack_a: Pointer to the head of stack_a where values will be added.
 *
 * This function handles both single and multiple command line arguments.
 * If there is a single argument, it splits the argument string into separate
 * values, otherwise, it directly uses the arguments.
 *
 * Return: Pointer to the head of stack_a.
 */

static t_node	*parse_arguments(int argc, char *argv[], t_node **stack_a)
{
	int			i;
	int			value;
	char		**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			error_message();
	}
	else
		split_argv = argv + 1;
	i = 0;
	while (split_argv[i] != NULL)
	{
		value = ft_atol(split_argv[i]);
		add_node(stack_a, value);
		i++;
	}
	if (argc == 2)
		free_split(split_argv);
	return (*stack_a);
}

/**
 * main - Entry point of the program.
 * @argc: Argument count from the command line.
 * @argv: Argument values from the command line.
 *
 * This function initializes the stacks, parses the arguments, checks for
 * duplicates, and then executes the push_swap algorithm, followed by clearing
 * the memory used for the stacks.
 */

int	main(int argc, char **argv)
{
	t_stacks		stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	error(argc, argv);
	stacks.stack_a = parse_arguments(argc, argv, &stacks.stack_a);
	if (!stacks.stack_a)
		clear_list(&stacks.stack_a);
	check_duplicates_list(stacks.stack_a);
	push_swap(&stacks);
	clear_list(&stacks.stack_a);
	clear_list(&stacks.stack_b);
}
