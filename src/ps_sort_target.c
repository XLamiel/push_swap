
#include "push_swap.h"

// Caso 1: encontrar posición del mínimo en la lista
int	find_min_pos(t_stack *a, int min_val)
{
	t_node	*current;
	int		pos;

	current = a->top;
	pos = 0;
	while (current)
	{
		if (current->value == min_val)
			return (pos);
		current = current->next;
		pos++;
	}
	return (0);
}

// Caso 2: encontrar la posición entre dos valores consecutivos
int	find_insert_pos(t_stack *a, int val)
{
	t_node	*current;
	int		pos;

	current = a->top;
	pos = 0;
	while (current && current->next)
	{
		if (val > current->value && val < current->next->value)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (0);
}

// Función principal que delega en los casos anteriores
int	get_a_target_pos(t_stack *a, int val)
{
	int	min_val;
	int	max_val;

	get_min_max(a, &min_val, &max_val);
	if (val < min_val || val > max_val)
		return (find_min_pos(a, min_val));
	else
		return (find_insert_pos(a, val));
}
