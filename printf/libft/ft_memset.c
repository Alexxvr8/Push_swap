/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:46:30 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:35:09 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Traverse the memory block byte by byte
2 - Fill each byte with the specified value
3 - Continue until n bytes have been written
4 - Return the original pointer
*/

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
