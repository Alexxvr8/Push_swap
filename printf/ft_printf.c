/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:15:00 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/22 16:44:29 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
1 - Check which format specifier follows the '%'
2 - Call the corresponding print function
3 - Consume the argument from va_list
*/

static void	select_format(char type, va_list *ap, int *len)
{
	if (type == 'c')
		print_char(va_arg(*ap, int), len);
	if (type == 's')
		print_str(va_arg(*ap, char *), len);
	if (type == 'i' || type == 'd')
		print_nbr(va_arg(*ap, int), len);
	if (type == 'u')
		print_unbr(va_arg(*ap, unsigned int), len);
	if (type == 'x' || type == 'X')
		print_hex(va_arg(*ap, unsigned int), type, len);
	if (type == 'p')
		print_ptr(va_arg(*ap, void *), len);
	if (type == '%')
		print_char('%', len);
}

/*
1 - Traverse the format string character by character
2 - If '%' is found, dispatch to select_format with the next character
3 - Advance two positions to skip '%' and the specifier
4 - Otherwise write the character directly and increment len
5 - Stop early if a write error sets len to -1
*/

static void	print_all(int *len, char const *fmt, va_list *ap)
{
	while (*fmt && *len >= 0)
	{
		if (*fmt == '%')
		{
			select_format(*(fmt + 1), ap, len);
			fmt += 2;
		}
		else
		{
			write(1, fmt, 1);
			fmt++;
			(*len)++;
		}
	}
}

/*
1 - Return -1 immediately if fmt is NULL
2 - Initialize the variadic argument list
3 - Process the format string and write output
4 - Clean up the va_list
5 - Return the total number of characters written, or -1 on error
*/

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	print_all(&len, fmt, &ap);
	va_end(ap);
	return (len);
}
