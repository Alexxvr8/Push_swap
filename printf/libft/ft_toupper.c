/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:14:43 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:47:47 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check if the character is a lowercase letter
2 - Convert it to its uppercase equivalent if necessary
3 - Return the resulting character
*/

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}
