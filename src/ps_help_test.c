
#include "push_swap.h"

// Funciones para imprimir stacks
void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
	{
		ft_printf("Empty\n");
		return;
	}
	current = stack->top;
	while (current) {
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("--- Stacks ---\n");
	ft_printf("Stack A: ");
	print_stack(a);
	ft_printf("Stack B: ");
	print_stack(b);
	ft_printf("--------------\n");
}
