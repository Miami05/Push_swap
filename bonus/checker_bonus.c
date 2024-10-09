/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledio <ledio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:48:40 by ledio             #+#    #+#             */
/*   Updated: 2024/10/09 13:34:46 by ledio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * execute_operations - Executes a given operation on the stacks.
 * @stack: Pointer to the t_stacks structure containing the stacks.
 * @operations: String representing the operation to execute.
 * 
 * This function compares the operations string with predefined commands 
 * and executes the corresponding stack operation. If the operation is 
 * unrecognized, it calls free_operations to handle errors and free 
 * resources.
 */

void	execute_operations(t_stacks *stack, char *operations)
{
	if (!ft_strcmp(operations, "sa\n"))
		sa(&stack->stack_a);
	else if (!ft_strcmp(operations, "sb\n"))
		sb(&stack->stack_b);
	else if (!ft_strcmp(operations, "ss\n"))
		ss(&stack->stack_a, &stack->stack_b);
	else if (!ft_strcmp(operations, "pa\n"))
		pa(&stack->stack_a, &stack->stack_b);
	else if (!ft_strcmp(operations, "pb\n"))
		pb(&stack->stack_b, &stack->stack_a);
	else if (!ft_strcmp(operations, "ra\n"))
		ra(&stack->stack_a);
	else if (!ft_strcmp(operations, "rb\n"))
		rb(&stack->stack_b);
	else if (!ft_strcmp(operations, "rr\n"))
		rr(&stack->stack_a, &stack->stack_b);
	else if (!ft_strcmp(operations, "rra\n"))
		rra(&stack->stack_a);
	else if (!ft_strcmp(operations, "rrb\n"))
		rrb(&stack->stack_b);
	else if (!ft_strcmp(operations, "rrr\n"))
		rrr(&stack->stack_a, &stack->stack_b);
	else
		free_operations(stack, operations);
}

/**
 * get_commands - Reads commands from standard input and executes them.
 * @stack: Pointer to the t_stacks structure containing the stacks.
 * 
 * This function continuously reads operations from standard input using 
 * get_next_line. For each operation, it calls execute_operations to 
 * perform the corresponding action on the stacks. After all operations, 
 * it checks if stack_a is sorted and prints "OK" or "KO".
 */

void	get_commands(t_stacks *stack, int visual)
{
	char		*operations;

	operations = get_next_line(0);
	while (operations)
	{
		execute_operations(stack, operations);
		if (visual == 1)
			print_stack(stack);
		free(operations);
		operations = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(&stack->stack_a) && len_of_stack(&stack->stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

/**
 * free_split - Frees the memory allocated for a split array of strings.
 * @split_argv: Array of strings to free.
 * 
 * This function iterates through the array, freeing each string, 
 * and finally frees the array itself to prevent memory leaks.
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
 * @argc: Argument count.
 * @argv: Argument vector.
 * @stack_a: Pointer to the head of stack_a.
 * 
 * This function checks if there are multiple arguments or a single one 
 * that needs to be split. It converts the argument(s) to integers 
 * and adds them as nodes to stack_a. If splitting is done, it frees 
 * the split array after use.
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
 * @argc: Argument count.
 * @argv: Argument vector.
 * 
 * This function initializes the stacks, checks for errors in input,
 * parses the arguments into stack_a, and processes the commands 
 * from standard input. It also handles cleanup at the end to free 
 * allocated resources.
 * 
 * Return: 0 on success.
 */

int	main(int argc, char **argv)
{
	t_stacks		stacks;
	int				visual;

	visual = 0;
	visual = check_visual(&argc, argv, visual);
	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	error(argc, argv);
	stacks.stack_a = parse_arguments(argc, argv, &stacks.stack_a);
	if (!stacks.stack_a)
		clear_list(&stacks.stack_a);
	check_duplicates_list(stacks.stack_a);
	get_commands(&stacks, visual);
	clear_all(&stacks);
}
