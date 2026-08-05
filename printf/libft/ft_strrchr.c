/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:21:58 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:46:19 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Traverse the string from beginning to end
2 - Keep track of the last occurrence of the target character
3 - Update the saved position whenever a match is found
4 - Check if the target character is the null terminator
5 - Return the last matching position found
6 - Return NULL if the character does not appear in the string
*/

char	*ft_strrchr(const char *str, int c)
{
	char	*res;

	res = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			res = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		res = (char *)str;
	return (res);
}
