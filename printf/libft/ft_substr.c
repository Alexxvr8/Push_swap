/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:36:27 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:47:32 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check that the source string pointer is valid
2 - Get the length of the source string
3 - Handle the case where the start position is beyond the end of the string
4 - Adjust the requested length if it exceeds the available characters
5 - Allocate memory for the substring and its null terminator
6 - Return NULL if the allocation fails
7 - Copy the requested characters into the new string
8 - Add a null terminator at the end
9 - Return the resulting substring
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= (unsigned int)s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
