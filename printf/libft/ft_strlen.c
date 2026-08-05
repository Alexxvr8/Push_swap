/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:00:36 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:45:45 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Initialize a length counter
2 - Traverse the string character by character
3 - Increment the counter for each character found
4 - Stop when the null terminator is reached
5 - Return the total length of the string
*/

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}
