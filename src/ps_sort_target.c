/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:10:52 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:15:14 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Case 1: find min possition into the lista
int	find_min_pos(t_stack *a, int min_val)
{
	t_node	*current;
	int		pos;

	current = a->top;
	pos = 0;
	while (current)
	{
		if (current->value == min_val)
			return (pos);
		current = current->next;
		pos++;
	}
	return (0);
}

// Case 2: find the possition between two consecutive values
int	find_insert_pos(t_stack *a, int val)
{
	t_node	*current;
	int		pos;

	current = a->top;
	pos = 0;
	while (current && current->next)
	{
		if (val > current->value && val < current->next->value)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (0);
}

// Pral. function that delegate in case1 and case2
int	get_a_target_pos(t_stack *a, int val)
{
	int	min_val;
	int	max_val;

	get_min_max(a, &min_val, &max_val);
	if (val < min_val || val > max_val)
		return (find_min_pos(a, min_val));
	else
		return (find_insert_pos(a, val));
}
