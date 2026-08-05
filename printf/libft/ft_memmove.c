/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:28:01 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:35:00 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check if both source and destination pointers are NULL
2 - Cast the pointers for byte-by-byte access
3 - Determine whether the memory regions overlap
4 - Copy forward if the destination is before the source
5 - Copy backward if the destination overlaps the source
6 - Return the destination pointer
*/

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s > d)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dst);
}
