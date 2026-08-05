/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:22:10 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:45:56 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check that the string and function pointers are valid
2 - Allocate memory for the new string
3 - Return NULL if the allocation fails
4 - Apply the function to each character and its index
5 - Store the transformed character in the new string
6 - Add a null terminator at the end
7 - Return the newly created string
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	map = malloc(ft_strlen(s) + 1);
	if (!map)
		return (NULL);
	while (s[i])
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
