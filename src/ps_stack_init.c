/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:16:32 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:16:47 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

void	load_stack(t_stack *a, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		push(a, ft_atoi(argv[i]));
		i--;
	}
}

void	free_stack(t_stack *s)
{
	int	val;

	while (s->top)
		pop(s, &val);
}
