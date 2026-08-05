/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:03:17 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:31:51 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Initialize a counter to zero
2 - Traverse the list node by node
3 - Increment the counter for each node found
4 - Continue until the end of the list is reached
5 - Return the total number of nodes
*/

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
