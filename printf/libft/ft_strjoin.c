/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:13:00 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:45:01 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Allocate memory for the combined length of both strings
2 - Return NULL if the allocation fails
3 - Copy all characters from the first string
4 - Append all characters from the second string
5 - Add a null terminator at the end
6 - Return the newly created string
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*join;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
