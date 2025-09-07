
#include "push_swap.h"

void	execute_double_moves(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_moves_a(t_stack *a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

void	execute_moves_b(t_stack *b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

void	execute_moves(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	execute_double_moves(a, b, &cost_a, &cost_b);
	execute_moves_a(a, &cost_a);
	execute_moves_b(b, &cost_b);
}
