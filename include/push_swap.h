/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:50:01 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/07/30 17:17:54 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

// Estructura per les dades que anira dins del node
typedef struct Data
{
	int	data;
	int	position_order;
	int	cost_a;
	int	cost_b;
}	t_Data;

// Estructura per el node de la llista
typedef struct Node
{
	t_Data		*data;	// Punter a les dades
	struct Node	*prev;	// Punter al node anterior
	struct Node	*next;	// Punter al node siguent
}	t_Node;

// Informacio per la llista de doble enllac,
typedef struct List
{
	t_Node	*head;		// Punter al primer node
	t_Node	*tail;		// Punter al ultim node
	size_t	count;		// Contador de elements
}	t_List;

// Funcions per gestionar llistes
/**
 * Crea una nova estructura de dades Data
 * @param data Valor entero para el campo data
 * @param data valor int per el camp data
 * @param position_order Ordre de possicio
 * @param cost_A Cost A
 * @param cost_B Cost B
 * @return Punter a la nova estructura Data creada
 */
t_Data	*create_data(int data, int position_order, int cost_a, int cost_b);

/**
 * Crea un nou node amb les dades proporcionats
 * @param data Punter a l'estructura Data
 * @return Punter al nou node creat
 */
t_Node	*create_node(t_Data *data);

/**
 * Inicializa una nueva lista doblemente enlazada
 * Inicilitza una nova llista doblement enllac,ada
 * @return Una nova llista buida
 */
t_List	*create_list(void);

/**
 * Afegeix un node al principi de la llista
 * @param list Llista on s'afegira el node
 * @param node Node per afegir
 */
void	add_first(t_List *list, t_Node *node);

/**
 * Afegeix un node al final de la llista
 * @param list Llista on s'afegira el node
 * @param node Node per afegir
 */
void	add_last(t_List *list, t_Node *node);

/**
 * Elimina un node de la llista, alliberant la memoria
 *    junatament amb la de les dades
 * @param list Llista on s'eliminara el node
 * @param node Node per eliminar
 */
void	delete_node(t_List *list, t_Node *node);

#endif
