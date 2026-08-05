/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:39:27 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:55:00 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Compare both strings character by character
2 - Stop if a difference is found, a null terminator is reached, 
	or n characters have been compared
3 - Return 0 if the first n characters are equal
4 - Return the difference between the first mismatching characters otherwise
*/

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
