/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_ops2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:20:41 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:20:48 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*current;

	*min = INT_MAX;
	*max = INT_MIN;
	current = stack->top;
	while (current)
	{
		if (current->value < *min)
			*min = current->value;
		if (current->value > *max)
			*max = current->value;
		current = current->next;
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a->size <= 1)
		return (1);
	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
