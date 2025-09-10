/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:17:27 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/09 15:17:34 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (1);
	init_stack(&a);
	init_stack(&b);
	load_stack(&a, argc, argv);
	if (!is_sorted(&a))
		sort_stack(&a, &b);
	rotate_min_top(&a);
	print_stacks(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
