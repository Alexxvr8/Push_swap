/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:01:13 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:36:35 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Allocate memory for a copy of the string including the null terminator
2 - Return NULL if the allocation fails
3 - Copy each character from the source string
4 - Add the null terminator at the end of the copy
5 - Return the duplicated string
*/

char	*ft_strdup(const char *s)
{
	int		i;
	char	*copy;

	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
