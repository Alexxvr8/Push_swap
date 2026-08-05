/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:56:09 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:45:37 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Calculate the length of the source string
2 - Handle the special case where the destination size is zero
3 - Copy characters from the source string into the destination
4 - Stop when the buffer limit is reached or the source ends
5 - Add a null terminator to the destination string
6 - Return the length of the source string
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l_src;
	size_t	i;

	i = 0;
	l_src = ft_strlen(src);
	if (size == 0)
		return (l_src);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l_src);
}
