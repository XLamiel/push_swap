
#include "push_swap.h"

void	get_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*current;

	*min = INT_MAX;
	*max = INT_MIN;
	current = stack->top;
	while (current)
	{
		if (current->value < *min)
			*min = current->value;
		if (current->value > *max)
			*max = current->value;
		current = current->next;
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a->size <= 1)
		return (1);
	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
