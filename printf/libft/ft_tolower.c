/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:27:14 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:47:39 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check if the character is an uppercase letter
2 - Convert it to its lowercase equivalent if necessary
3 - Return the resulting character
*/

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}
