/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:43:48 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:30:37 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check that both the list and new node pointers are valid
2 - If the list is empty, make the new node the first element
3 - Otherwise, move through the list until reaching the last node
4 - Link the last node to the new node
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
