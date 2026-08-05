/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:03:08 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:55:14 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Initialize value to store the final number and sign as positive
2 - Skip all leading whitespace characters
3 - Check if the number is negative and update sign if needed
4 - Skip the sign character if '+' or '-' is present
5 - Convert each digit character into its numeric value
6 - Build the final number by multiplying the current value 
	by 10 and adding the new digit
7 - Return the number multiplied by its sign
*/

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + (*str - '0');
		str++;
	}
	return (value * sign);
}
