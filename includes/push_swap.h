/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurmish <ldurmish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:26:34 by ledio             #+#    #+#             */
/*   Updated: 2025/01/14 21:53:39 by ldurmish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "errors.h"
# include "libft.h"

typedef struct node
{
	int				data;
	struct node		*next;
	struct node		*prev;
}	t_node;

typedef struct t_cheap
{
	int			cost;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_cheap;

typedef struct t_moves
{
	int			cost;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_moves;

typedef struct t_values
{
	int			max_a;
	int			max_b;
	int			min_a;
	int			min_b;
}	t_values;

typedef struct t_stacks
{
	t_node		*stack_a;
	t_node		*stack_b;
	t_values	*values;
	t_moves		*moves;
	t_cheap		*cheap;
}	t_stacks;

int								str_to_int(const char *str);
char							**ft_split(const char *str, char c);
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
void							rrr(t_node **rra, t_node **rrb);
void							*clear_list(t_node **head);
t_node							*add_node(t_node **head, int data);
void							sort_three(t_node **stack_a);
void							sort_five(t_node **stack_a, t_node **stack_b);
bool							is_sorted(t_node **stack_a);
void							push_swap(t_stacks *stack);
void							cheapest_move(t_stacks *stack);
void							check_max_and_min_in_b(t_stacks *stack);
void							get_element_top_stack_a(t_stacks *stack,
									t_node *head, int i);
void							new_min_or_max_stack_b(t_stacks *stack);
int								find_index_stack_b(t_stacks *stack,
									int target_value);
void							check_cheapest_moves(t_stacks *stack);
void							new_num_in_stack_b(t_stacks *stack, int num);
int								search_new_num_in_stack_b(t_stacks *stack,
									int num);
void							push_to_a(t_stacks *stack);
void							check_max_and_min_in_a(t_stacks *stack);
int								find_index_stack_a(t_stacks *stack, int nbr);
void							new_max_num_in_a(t_stacks *stack);
void							new_min_num_in_a(t_stacks *stack);
void							new_num_in_stack_a(t_stacks *stack,
									t_node *stack_b);

#endif