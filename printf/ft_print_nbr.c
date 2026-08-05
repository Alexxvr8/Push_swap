/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:59:38 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/22 16:46:50 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
1 - Cast to long to safely handle INT_MIN without overflow
2 - If negative, print '-' and negate the value
3 - Recurse to print all digits before the current one
4 - Print the last digit using its ASCII offset
*/

void	print_nbr(int n, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		print_char('-', len);
		nb = -nb;
	}
	if (nb >= 10)
		print_nbr(nb / 10, len);
	print_char((nb % 10) + '0', len);
}

/*
1 - Recurse to print all digits before the current one
2 - Print the last digit using its ASCII offset
*/
void	print_unbr(unsigned int n, int *len)
{
	if (n >= 10)
		print_unbr(n / 10, len);
	print_char((n % 10) + '0', len);
}

/*
1 - Select the correct digit set based on upper or lower case
2 - Recurse to print all digits before the current one
3 - Print the current digit from the base string
*/

void	print_hex(unsigned long n, char type, int *len)
{
	char	*base;

	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16, type, len);
	print_char(base[n % 16], len);
}

/*
1 - If the pointer is NULL, print "(nil)" and return
2 - Print the "0x" prefix
3 - Print the address as a lowercase hexadecimal number
*/

void	print_ptr(void *ptr, int *len)
{
	if (!ptr)
	{
		print_str("(nil)", len);
		return ;
	}
	print_str("0x", len);
	print_hex((unsigned long)ptr, 'x', len);
}
