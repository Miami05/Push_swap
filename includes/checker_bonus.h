/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 01:01:12 by ledio             #+#    #+#             */
/*   Updated: 2025/01/20 22:23:02 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "errors.h"
# include "libft.h"

void							clear_all(t_stacks *stack);
void							free_operations(t_stacks *stack,
									char *operations);
t_node							*add_node(t_node **head, int data);
void							*clear_list(t_node **head);
void							sa(t_node **stack_a);
void							sb(t_node **stack_b);
void							ss(t_node **stack_a, t_node **stack_b);
void							pa(t_node **stack_a, t_node **stack_b);
void							pb(t_node **stack_b, t_node **stack_a);
t_node							**ra(t_node **stack_a);
t_node							**rb(t_node **stack_b);
void							rr(t_node **stack_a, t_node **stack_b);
t_node							**rra(t_node **stack_a);
t_node							**rrb(t_node **stack_b);
void							rrr(t_node **stack_a, t_node **stack_b);
void							print_stack(t_stacks *stack);
int								check_visual(int *argc,
									char **argv, int visual);

#endif