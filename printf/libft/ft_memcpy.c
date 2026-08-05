/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:10:22 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:34:54 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check if both source and destination pointers are NULL
2 - Traverse the memory block byte by byte
3 - Copy each byte from the source to the destination
4 - Continue until n bytes have been copied
5 - Return the destination pointer
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
