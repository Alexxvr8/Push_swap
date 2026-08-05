/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:42:04 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:24:51 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Check if the character is alphabetic
2 - Check if the character is numeric
3 - Return true if either condition is true
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
