/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 11:57:54 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:31:35 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check that the list and function pointers are valid
2 - Create an empty destination list
3 - Apply the function to the content of each node
4 - Create a new node with the transformed content
5 - If node creation fails, clear the new list and return NULL
6 - Add each new node to the end of the destination list
7 - Continue until all original nodes have been processed
8 - Return the newly created list
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
