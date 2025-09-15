/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_ops1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:16:56 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:17:06 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push(t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

int	pop(t_stack *stack, int *val)
{
	t_node	*tmp;

	if (!stack->top)
		return (0);
	tmp = stack->top;
	*val = tmp->value;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (1);
}
