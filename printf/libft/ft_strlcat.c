/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:46:45 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:45:30 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Calculate the lengths of the destination and source strings
2 - Handle edge cases where the buffer size is too small
3 - Append characters from the source string to the destination
4 - Stop when the buffer is full or the source ends
5 - Add a null terminator to the destination string
6 - Return the length the resulting string would have had
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	i;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size == 0)
		return (l_src);
	if (size <= l_dst)
		return (size + l_src);
	i = 0;
	while (i + l_dst < size - 1 && src[i])
	{
		dst[i + l_dst] = src[i];
		i++;
	}
	dst[i + l_dst] = '\0';
	return (l_dst + l_src);
}
