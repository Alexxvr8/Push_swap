/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:01:36 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:26:56 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Place the null terminator at the end of the string
2 - Start filling the string from the last position backwards
3 - Extract the last digit of the number using modulo 10
4 - Convert the digit to its character representation and store it
5 - Remove the processed digit from the number
6 - Repeat until all digit positions are filled
7 - Add the negative sign at the beginning if needed
8 - Return the completed string
*/

static	char	*ft_fill_num(char *res, long num, int negative, size_t len)
{
	size_t	i;

	res[len] = '\0';
	i = len;
	while (i > (size_t)negative)
	{
		i--;
		res[i] = '0' + num % 10;
		num /= 10;
	}
	if (negative)
		res[0] = '-';
	return (res);
}

/*
1 - Allocate memory for the string "0" and its null terminator
2 - Return NULL if the allocation fails
3 - Store the character '0' in the first position
4 - Add the null terminator at the end
5 - Return the allocated string
*/

static	char	*ft_malloc_zero(void)
{
	char	*res;

	res = malloc(2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

/*
1 - Initialize the length counter
2 - Count how many digits the number contains
3 - Divide the number by 10 after each digit counted
4 - Continue until the number becomes zero
5 - Add one extra position if the number is negative
6 - Return the total required length
*/

static	size_t	ft_len_int(int negative, long num)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len + negative);
}

/*
1 - Handle the special case where the number is zero
2 - Determine whether the number is negative
3 - Convert the number to a positive long value if needed
4 - Calculate the length required for the resulting string
5 - Allocate memory for the string and its null terminator
6 - Return NULL if the allocation fails
7 - Fill the allocated string with the digits of the number
8 - Return the resulting string
*/

char	*ft_itoa(int a)
{
	long	num;
	int		negative;
	size_t	len;
	char	*res;

	if (a == 0)
		return (ft_malloc_zero());
	negative = 0;
	if (a < 0)
	{
		num = -(long)a;
		negative = 1;
	}
	else
		num = (long)a;
	len = ft_len_int(negative, num);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	return (ft_fill_num(res, num, negative, len));
}
