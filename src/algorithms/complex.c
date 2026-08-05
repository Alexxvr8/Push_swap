/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:18:51 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:42:27 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Return the value (0 or 1) of the given bit of the index
*/
static int	get_bit(int index, int bit)
{
	return ((index >> bit) & 1);
}

/*
1 - Count how many bits are needed to represent n
*/
static int	max_bit(int n)
{
	int	bits;

	bits = 0;
	while (n >> bits)
		bits++;
	return (bits);
}

/*
1 - Repeat one pass per bit, from least to most significant
2 - Push to b when the current bit is 0, rotate a when it is 1
3 - Push every element back to a at the end of each pass
4 - After the last bit the stack is fully sorted (radix sort)
*/
void	ft_complex_algorithm(t_data *data)
{
	int		bit;
	int		i;
	int		size;

	bit = 0;
	size = data->size_a;
	while (bit < max_bit(size))
	{
		i = 0;
		while (i++ < size)
		{
			if (get_bit(data->a_top->index, bit) == 0)
				ft_p(data, 'b');
			else
				ft_r(data, 'a');
		}
		while (data->size_b)
			ft_p(data, 'a');
		bit++;
	}
}
