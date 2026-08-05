/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:42:18 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:42:57 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Compute the integer square root of n as the chunk size
2 - Never return less than 1
*/
static int	get_chunk_size(int n)
{
	int	r;

	r = 0;
	while ((r + 1) * (r + 1) <= n)
		r++;
	if (r < 1)
		r = 1;
	return (r);
}

/*
1 - Compute the chunk size from the current stack size
2 - Push to b every element whose index falls in the current window
3 - Rotate b to keep the smaller half of the chunk in place
4 - Rotate a to reach the next candidate when the top is out of range
*/
static void	push_chunk(t_data *data)
{
	int	chunk;
	int	pushed;

	chunk = get_chunk_size(data->size_a);
	pushed = 0;
	while (data->size_a > 0)
	{
		if (data->a_top->index <= pushed + chunk)
		{
			ft_p(data, 'b');
			pushed++;
			if (data->b_top->index <= pushed - (chunk / 2))
				ft_r(data, 'b');
		}
		else
			ft_r(data, 'a');
	}
}

/*
1 - Walk stack b tracking the highest index seen
2 - Return the position of the element with the maximum index
*/
static int	find_max_pos(t_stack *b)
{
	int		pos;
	int		best_pos;
	int		best_index;

	pos = 0;
	best_pos = 0;
	best_index = b->index;
	while (b)
	{
		if (b->index > best_index)
		{
			best_index = b->index;
			best_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (best_pos);
}

/*
1 - Find the position of the maximum element in b
2 - Rotate b (rb) if it sits in the upper half
3 - Reverse rotate b (rrb) otherwise, taking the shorter path
*/
static void	max_to_top(t_data *data)
{
	int	pos;
	int	i;

	pos = find_max_pos(data->b_top);
	i = 0;
	if (pos <= (data->size_b) / 2)
	{
		while (i++ < pos)
			ft_r(data, 'b');
	}
	else
	{
		while (i++ < (data->size_b - pos))
			ft_rr(data, 'b');
	}
}

/*
1 - Distribute the elements into b in chunks
2 - Repeatedly bring the current maximum of b to the top and push it to a
*/
void	ft_medium_algorithm(t_data *data)
{
	push_chunk(data);
	while (data->size_b > 0)
	{
		max_to_top(data);
		ft_p(data, 'a');
	}
}
