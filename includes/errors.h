/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:47:39 by ledio             #+#    #+#             */
/*   Updated: 2025/01/09 19:24:07 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <unistd.h>
# include <stdbool.h>
# include "push_swap.h"

typedef struct node	t_node;
void							error_message(void);
void							error(int argc, char **argv);
bool							check_duplicates_list(t_node *stack_a);
int								check_integer_size(int argc, char **argv);
int								check_arguments(int argc, char **argv);
long							ft_atol(const char *str);
int								ft_strcmp(const char *s1, const char *s2);
int								len_of_stack(t_node **stack);

#endif