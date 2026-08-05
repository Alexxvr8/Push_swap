/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:33:05 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:30:59 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check that the list and delete function are valid
2 - Traverse the list node by node
3 - Save the next node before deleting the current one
4 - Delete the content using the provided function
5 - Free the current node
6 - Continue until all nodes have been removed
7 - Set the list pointer to NULL
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*current;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		del(current->content);
		free(current);
		current = temp;
	}
	*lst = NULL;
}
