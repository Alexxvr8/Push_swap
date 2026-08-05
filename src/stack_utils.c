/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:07:12 by alvicent          #+#    #+#             */
/*   Updated: 2026/08/02 21:47:16 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Write the operation name to standard output
2 - Increment the counter of this operation type
*/
void	log_op(char *op, int len, int *count)
{
	write(1, op, len);
	(*count)++;
}

/*
1 - Walk the linked list from the top
2 - Free each node while keeping a pointer to the next one
*/
void	free_stack(t_stack *top)
{
	t_stack	*tmp;

	while (top)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}
}

/*
1 - Free every string of the array
2 - Free the array of pointers itself
*/
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/*
1 - Allocate a new node and return NULL on failure
2 - Store the value and reset its index and links
3 - Return the new node
*/
t_stack	*lstnew(int nbr)
{
	t_stack	*n_node;

	n_node = malloc(sizeof(t_stack));
	if (!n_node)
		return (NULL);
	n_node->value = nbr;
	n_node->index = 0;
	n_node->next = NULL;
	n_node->prev = NULL;
	return (n_node);
}

/*
1 - Reject the operation on invalid pointers
2 - Make the node the head if the list is empty
3 - Walk to the last node, rejecting any duplicate value on the way
4 - Link the new node at the back of the list
*/
int	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!lst || !new)
		return (0);
	if (*lst == NULL)
	{
		*lst = new;
		return (1);
	}
	current = *lst;
	if (current->value == new->value)
		return (0);
	while (current->next != NULL)
	{
		current = current->next;
		if (current->value == new->value)
			return (0);
	}
	new->prev = current;
	current->next = new;
	return (1);
}
