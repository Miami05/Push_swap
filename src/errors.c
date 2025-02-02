/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:44:43 by ledio             #+#    #+#             */
/*   Updated: 2025/01/14 21:54:42 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

/**
 * check_integer_size - Checks if integers are within valid range
 * @argc: The number of command-line arguments
 * @argv: Array of argument strings
 *
 * This function iterates through all the arguments, converts them to long
 * integers using the ft_atol function, and checks if they fall within the
 * valid range of an integer (`INT_MIN` to `INT_MAX`). If any number is out
 * of range, it triggers an error message and exits the program.
 *
 * Return: 0 if all integers are within range, otherwise the function exits.
 */

int	check_integer_size(int argc, char **argv)
{
	long			num;
	int				i;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_message();
		i++;
	}
	return (0);
}

/**
 * error_message - Prints an error message and exits the program
 *
 * This function prints "Error\n" to the standard error output (`stderr`)
 * and then exits the program with a status code of 0. It is called whenever
 * an invalid argument or out-of-range integer is detected.
 */

void	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

/**
 * error - Validates arguments and triggers an error if necessary
 * @argc: The number of command-line arguments
 * @argv: Array of argument strings
 *
 * This function checks if the number of arguments is valid and verifies
 * that all arguments are integers within the valid range. If any of these
 * checks fail, it calls `error_message()` to print an error and exit.
 */

void	error(int argc, char **argv)
{
	if (argc == 1 || check_arguments(argc, argv)
		|| check_integer_size(argc, argv))
		error_message();
}

/**
 * is_sorted - Checks if the stack is sorted in ascending order
 * @stack_a: Double pointer to the head of the stack
 *
 * This function checks if the linked list (stack) is sorted in ascending order.
 * It iterates through the list, comparing each node's data with the next one.
 * If any node has a value greater than the next node,
 * it returns `false`, meaning
 * the list is not sorted. If the list is empty or sorted, it returns `true`.
 *
 * Return: `true` if the list is sorted or empty, `false` otherwise.
 */

bool	is_sorted(t_node **stack_a)
{
	t_node		*current;

	if (*stack_a == NULL)
		return (true);
	current = *stack_a;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}
