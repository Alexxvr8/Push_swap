/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:29:54 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:36:27 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Traverse the string character by character
2 - Compare each character with the target character
3 - Return a pointer to the first match if found
4 - Check if the target character is the null terminator
5 - Return a pointer to the terminator if requested
6 - Return NULL if no match is found
*/

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
