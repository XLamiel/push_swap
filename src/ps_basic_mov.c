/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_basic_mov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:04:49 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:05:24 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// basic movements
void	swap(t_stack *stack)
{
	int		temp;
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*cur;

	if (stack->size < 2)
		return ;
	prev = NULL;
	cur = stack->top;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	if (prev)
		prev->next = NULL;
	cur->next = stack->top;
	stack->top = cur;
}
