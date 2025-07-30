/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:55:13 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/30 16:59:20 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*create_node(t_Data *data)
{
	t_Node	*new_node;

	new_node = (t_Node *)malloc(sizeof(t_Node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_List	*create_list(void)
{
	t_List	*new_list;

	new_list = (t_List *)malloc(sizeof(t_List));
	if (new_list == NULL)
		return (NULL);
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->count = 0;
	return (new_list);
}

void	add_first(t_List *list, t_Node *node)
{
	if (list == NULL || node == NULL)
		return ;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->count++;
}

void	add_last(t_List *list, t_Node *node)
{
	if (list == NULL || node == NULL)
		return ;
	if (list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	list->count++;
}

void	delete_node(t_List *list, t_Node *node)
{
	if (list == NULL || node == NULL)
		return ;
	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		list->head = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	else
		list->tail = node->prev;
	if (node->data != NULL)
		free(node->data);
	free(node);
	list->count--;
}
