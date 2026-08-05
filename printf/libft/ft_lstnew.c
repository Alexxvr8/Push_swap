/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:24:29 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:31:43 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Allocate memory for a new list node
2 - Return NULL if the allocation fails
3 - Store the provided content in the node
4 - Set the next pointer to NULL
5 - Return the newly created node
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*n_node;

	n_node = malloc(sizeof(t_list));
	if (!n_node)
		return (NULL);
	n_node->content = content;
	n_node->next = NULL;
	return (n_node);
}
