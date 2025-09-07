
#include "push_swap.h"

int	find_min_position(t_stack *a, int *min_val)
{
	t_node	*current;
	int		min_pos;
	int		pos;

	min_pos = 0;
	pos = 0;
	current = a->top;
	*min_val = INT_MAX;
	while (current)
	{
		if (current->value < *min_val)
		{
			*min_val = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	rotate_value_to_top(t_stack *a, int value, int pos)
{
	if (pos <= a->size / 2)
	{
		while (a->top->value != value)
			ra(a);
	}
	else
	{
		while (a->top->value != value)
			rra(a);
	}
}

void	rotate_min_top(t_stack *a)
{
	int	min_val;
	int	min_pos;

	min_pos = find_min_position(a, &min_val);
	rotate_value_to_top(a, min_val, min_pos);
}
