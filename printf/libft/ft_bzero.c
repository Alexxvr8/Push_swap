/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:19:44 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:24:34 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Initialize an index to start from the first byte
2 - Loop through the memory block while there are bytes left to clear
3 - Set each byte to zero
4 - Continue until n bytes have been cleared
*/

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
}
