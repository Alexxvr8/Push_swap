/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:28:21 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:46:11 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Return the start of the string if the substring is empty
2 - Traverse the main string within the specified length limit
3 - Compare the substring with the current position in the main string
4 - Continue matching characters while they are equal
5 - Return a pointer to the match if the entire substring is found
6 - Continue searching until the limit is reached
7 - Return NULL if no match is found
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	size_t			k;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		k = i;
		while (big[k] == little[j] && k < len && little[j])
		{
			j++;
			k++;
		}
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
