/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:44:30 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/08/03 21:42:01 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "libft.h"
//#include "/home/xlamiel-/gitroot/libft/include/libft.h"
#include <stdio.h>  // Para printf

int		is_valid_input(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s) || *s == ' ')
			s++;
		else
			return (0);
	}
	return (1);
}

void	free_arr_string(char ***arr_string)
{
	size_t	i;

	if (!arr_string || !*arr_string)
		return;
	i = 0;
	while ((*arr_string)[i])
	{
		free((*arr_string)[i]);
		i++;
	}
	free(*arr_string);
	*arr_string = NULL;
}

void	print_list(const t_List *list)
{
	t_Node	*current = list->head;

	printf("Contenido de la lista (%zu elementos):\n", list->count);
	while (current != NULL)
	{
		ft_printf("  data = %d, pos = %d, cost_a = %d, cost_b = %d\n",
			current->data->data,
			current->data->position_order,
			current->data->cost_a,
			current->data->cost_b);
		current = current->next;
	}
}

// Función auxiliar para liberar toda la lista
void	free_list(t_List *list)
{
	t_Node *current = list->head;
	t_Node *next;

	while (current != NULL)
	{
		next = current->next;
		delete_node(list, current);
		current = next;
	}
	free(list);
}

int	main(int argc, char *argv[])
{
	char	**arr_string;

	if (argc != 2)
		return (0);
	if (!is_valid_input(argv[1]))
		return (0);
	arr_string = ft_split(argv[1], ' ');
	if (!arr_string)
		return (0);
	ft_printf("Correcte\n");
	free_arr_string(&arr_string);
	// Crear la lista
	t_List	*list = create_list();
	if (list == NULL)
	{
		fprintf(stderr, "Error al crear la lista.\n");
		return (1);
	}

	// Añadir algunos nodos
	t_Data	*data1 = create_data(10, 1, 2, 3);
	t_Data	*data2 = create_data(20, 2, 4, 1);
	t_Data	*data3 = create_data(30, 3, 1, 5);
	t_Data	*data4 = create_data(40, 4, 0, 0);

	add_first(list, create_node(data1));  // 10
	add_last(list, create_node(data2));   // 10 -> 20
	add_first(list, create_node(data3));  // 30 -> 10 -> 20
	add_last(list, create_node(data4));   // 30 -> 10 -> 20 -> 40

	// Imprimir la lista
	print_list(list);

	// Eliminar un nodo (por ejemplo el segundo)
	if (list->head && list->head->next)
		delete_node(list, list->head->next); // elimina el nodo 10

	// Imprimir después de borrar
	printf("\nDespués de eliminar un nodo:\n");
	print_list(list);

	// Liberar memoria
	free_list(list);

	return (0);
}
