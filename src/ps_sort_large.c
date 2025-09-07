
#include "push_swap.h"

void	move_all_but_three(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
}

t_cost	find_best_move(t_stack *a, t_stack *b)
{
	int		pos_b;
	t_node	*cur;
	t_cost	best;
	t_cost	cur_cost;

	pos_b = 0;
	cur = b->top;
	best.cost = INT_MAX;
	while (cur)
	{
		cur_cost = evaluate_move(a, b, cur->value, pos_b);
		if (cur_cost.cost < best.cost)
			best = cur_cost;
		cur = cur->next;
		pos_b++;
	}
	return (best);
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	t_cost	best;

	while (b->size > 0)
	{
		best = find_best_move(a, b);
		execute_moves(a, b, best.a_moves, best.b_moves);
		pa(a, b);
	}
}

void	sort_large_stack(t_stack *a, t_stack *b)
{
	move_all_but_three(a, b);
	move_back_to_a(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size <= 3)
		sort_three(a);
	else
		sort_large_stack(a, b);
}
