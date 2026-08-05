/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:52:14 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:24:41 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check for integer overflow before calculating the allocation size
2 - Allocate memory for count elements of size bytes each
3 - Return NULL if the allocation fails
4 - Set all allocated bytes to zero using ft_bzero
5 - Return the pointer to the allocated memory
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count != 0 && size > (size_t)(-1) / count)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (count * size));
	return (mem);
}
