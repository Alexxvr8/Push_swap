/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:03:21 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/22 16:44:54 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
1 - Attempt to write the character to stdout
2 - If write fails, set len to -1 to signal the error
3 - Otherwise increment the character counter
*/

void	print_char(char c, int *len)
{
	if (write(1, &c, 1) == -1)
		(*len) = -1;
	else
		(*len)++;
}

/*
1 - If the pointer is NULL, substitute "(null)"
2 - Traverse the string character by character
3 - Write each character and stop on error or end of string
*/

void	print_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str && *len >= 0)
		print_char(*str++, len);
}
