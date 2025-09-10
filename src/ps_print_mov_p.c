/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_mov_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:07:37 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:07:45 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	val;

	if (b->size == 0)
		return ;
	if (pop(b, &val))
	{
		push(a, val);
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	val;

	if (a->size == 0)
		return ;
	if (pop(a, &val))
	{
		push(b, val);
		ft_printf("pb\n");
	}
}
