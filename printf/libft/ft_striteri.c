/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:52:09 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:44:54 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check that the string and function pointers are valid
2 - Initialize an index starting from zero
3 - Traverse the string character by character
4 - Apply the function to each character and its index
5 - Continue until the end of the string is reached
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
