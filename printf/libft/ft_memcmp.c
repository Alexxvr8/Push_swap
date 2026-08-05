/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:12:00 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:34:47 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Cast both memory blocks to unsigned char for byte comparison
2 - Traverse the first n bytes of both memory blocks
3 - Compare the bytes at each position
4 - Return the difference when the first mismatch is found
5 - Return 0 if all compared bytes are equal
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*res1;
	unsigned char	*res2;

	res1 = (unsigned char *)s1;
	res2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (res1[i] != res2[i])
			return (res1[i] - res2[i]);
		i++;
	}
	return (0);
}
