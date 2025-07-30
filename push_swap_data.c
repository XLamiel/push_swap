/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:57:30 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/30 17:19:03 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Data	*create_data(int data, int position_order, int cost_a, int cost_b)
{
	t_Data	*new_data;

	new_data = (t_Data *)malloc(sizeof(t_Data));
	if (new_data == NULL)
		return (NULL);
	new_data->data = data;
	new_data->position_order = position_order;
	new_data->cost_a = cost_a;
	new_data->cost_b = cost_b;
	return (new_data);
}
