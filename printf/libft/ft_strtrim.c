/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:04:25 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 13:17:38 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check that both s1 and set are not NULL
2 - Skip characters from the start of s1 as long as they are found in set
3 - Get the length of the remaining string to know where the end is
4 - Move the end backwards as long as the characters are found in set
5 - Return a substring of s1 from the new start with the valid length
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len]) && len)
		len--;
	return (ft_substr(s1, 0, len + 1));
}
