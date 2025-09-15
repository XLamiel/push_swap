/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:27:57 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/15 15:27:15 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_move_cost
{
	int	a_moves;
	int	b_moves;
	int	cost;
}	t_cost;

/* Stack initialization and memory management */
void	init_stack(t_stack *s);
void	load_stack(t_stack *a, int argc, char **argv);
void	free_stack(t_stack *s);

/* Basic stack operations */
t_node	*new_node(int value);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack, int *val);
void	get_min_max(t_stack *stack, int *min, int *max);
int		is_sorted(t_stack *a);

/* Basic movements (no output) */
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

/* Movement commands with output */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/* Move execution */
void	execute_double_moves(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	execute_moves_a(t_stack *a, int *cost_a);
void	execute_moves_b(t_stack *b, int *cost_b);
void	execute_moves(t_stack *a, t_stack *b, int cost_a, int cost_b);

/* Sorting algorithms */
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_large_stack(t_stack *a, t_stack *b);

/* Sorting utilities */
int		find_min_position(t_stack *a, int *min_val);
void	rotate_value_to_top(t_stack *a, int value, int pos);
void	rotate_min_top(t_stack *a);

/* Target position calculation */
int		find_min_pos(t_stack *a, int min_val);
int		find_insert_pos(t_stack *a, int val);
int		get_a_target_pos(t_stack *a, int val);

/* Cost calculation */
int		calc_moves(int size, int pos);
int		calc_total_cost(int a_moves, int b_moves);
t_cost	evaluate_move(t_stack *a, t_stack *b, int value, int pos_b);

/* Move execution */
void	execute_double_moves(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void	execute_moves_a(t_stack *a, int *cost_a);
void	execute_moves_b(t_stack *b, int *cost_b);
void	execute_moves(t_stack *a, t_stack *b, int cost_a, int cost_b);

/* Large sort specific functions */
void	move_all_but_three(t_stack *a, t_stack *b);
t_cost	find_best_move(t_stack *a, t_stack *b);
void	move_back_to_a(t_stack *a, t_stack *b);

/* Debugging utilities */
void	print_stack(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);

/* Three sort utilities */
void	get_top_three(t_stack *a, int *v1, int *v2, int *v3);

#endif
