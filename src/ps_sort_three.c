/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:15:37 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:15:47 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_top_three(t_stack *a, int *v1, int *v2, int *v3)
{
	*v1 = a->top->value;
	*v2 = a->top->next->value;
	*v3 = a->top->next->next->value;
}

void	sort_three(t_stack *a)
{
	int	v1;
	int	v2;
	int	v3;

	get_top_three(a, &v1, &v2, &v3);
	if (v1 > v2 && v2 < v3 && v1 > v3)
		ra(a);
	else if (v1 > v2 && v2 > v3)
	{
		sa(a);
		rra(a);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		rra(a);
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		sa(a);
		ra(a);
	}
	else if (v1 > v2 && v2 < v3)
		sa(a);
}
