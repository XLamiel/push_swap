/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_cost_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:34 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:05:49 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves(int size, int pos)
{
	if (pos > size / 2)
		return (pos - size);
	return (pos);
}

int	calc_total_cost(int a_moves, int b_moves)
{
	if ((a_moves > 0 && b_moves > 0) || (a_moves < 0 && b_moves < 0))
	{
		if (abs(a_moves) > abs(b_moves))
			return (abs(a_moves));
		return (abs(b_moves));
	}
	return (abs(a_moves) + abs(b_moves));
}

t_cost	evaluate_move(t_stack *a, t_stack *b, int value, int pos_b)
{
	t_cost	res;
	int		pos_a;

	pos_a = get_a_target_pos(a, value);
	res.a_moves = calc_moves(a->size, pos_a);
	res.b_moves = calc_moves(b->size, pos_b);
	res.cost = calc_total_cost(res.a_moves, res.b_moves);
	return (res);
}
