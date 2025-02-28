/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:41:39 by ledio             #+#    #+#             */
/*   Updated: 2025/01/14 21:58:57 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "push_swap.h"

/**
 * check_duplicates_list - Checks for duplicates in a linked list.
 * @stack_a: Pointer to the head of the stack.
 *
 * Return: true if duplicates are found, otherwise false.
 */

bool	check_duplicates_list(t_node *stack_a)
{
	t_node		*current;
	t_node		*temp;

	current = stack_a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->data == temp->data)
			{
				clear_list(&stack_a);
				error_message();
				return (true);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (false);
}

/**
 * check_arguments - Validates the input arguments.
 * @argc: Argument count.
 * @argv: Argument vector (array of strings).
 *
 * This function ensures that the arguments contain only valid integers.
 * If an invalid argument is found, it throws an error.
 *
 * Return: 0 if arguments are valid, otherwise throws an error.
 */

int	check_arguments(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		j = 0;
		while (arg[j])
		{
			while (arg[j] && arg[j] == ' ')
				j++;
			if (arg[j] == '-' || arg[j] == '+')
				j++;
			if (!arg[j] || (!ft_isdigit(arg[j]) && arg[j] != ' '))
				error_message();
			while (arg[j] && ft_isdigit(arg[j]))
				j++;
			if (arg[j] && arg[j] != ' ')
				error_message();
		}
		i++;
	}
	return (0);
}

/**
 * ft_atol - Converts a string to a long integer.
 * @str: String to convert.
 *
 * Return: The converted long integer.
 */

long	ft_atol(const char *str)
{
	long			sign;
	long			num;

	sign = 1;
	num = 0;
	while (*str == ' ' && (*str >= 9 || *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

/**
 * ft_strcmp - Compares two strings.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 *
 * Return: The difference between the two
 * strings at the first mismatched character.
 */

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/**
 * len_of_stack - Returns the length of a linked list stack.
 * @stack: Pointer to the stack.
 *
 * Return: The number of elements in the stack.
 */

int	len_of_stack(t_node **stack)
{
	int			count;
	t_node		*temp;

	temp = *stack;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
