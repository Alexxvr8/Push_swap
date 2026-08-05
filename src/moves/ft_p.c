/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 20:36:30 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:43:42 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Do nothing if the source stack is empty
2 - Detach the top node of the source stack
3 - Place it on top of the destination stack and fix the links
*/
static int	ft_px(t_stack **from, t_stack **to)
{
	t_stack	*moved;

	if (!(*from))
		return (0);
	moved = *from;
	*from = moved->next;
	if (*from)
		(*from)->prev = NULL;
	moved->prev = NULL;
	moved->next = *to;
	if (*to)
		(*to)->prev = moved;
	*to = moved;
	return (1);
}

/*
1 - Push from b to a, updating sizes and logging "pa"
2 - Push from a to b, updating sizes and logging "pb"
*/
void	ft_p(t_data *data, char objetive)
{
	if (objetive == 'a')
	{
		if (ft_px(&data->b_top, &data->a_top))
		{
			data->size_b--;
			data->size_a++;
			log_op("pa\n", 3, &data->count.pa);
		}
	}
	else if (objetive == 'b')
	{
		if (ft_px(&data->a_top, &data->b_top))
		{
			data->size_a--;
			data->size_b++;
			log_op("pb\n", 3, &data->count.pb);
		}
	}
}
