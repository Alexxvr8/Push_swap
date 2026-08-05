/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:57:02 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:34:41 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Cast the memory block to unsigned char for byte-by-byte access
2 - Traverse the first n bytes of the memory block
3 - Compare each byte with the target character
4 - Return a pointer to the first matching byte if found
5 - Return NULL if the character is not found within n bytes
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
			return ((void *)(res + i));
		i++;
	}
	return (NULL);
}
