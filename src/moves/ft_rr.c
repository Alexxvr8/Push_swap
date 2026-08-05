/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 23:30:36 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:44:11 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Do nothing if the stack has fewer than two elements
2 - Move the last element to the first position (reverse rotate)
*/
static int	ft_rrx(t_stack **top)
{
	t_stack	*last;

	if (!(*top) || !(*top)->next)
		return (0);
	last = *top;
	while (last->next)
		last = last->next;
	last->next = *top;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next->prev = last;
	*top = last;
	return (1);
}

/*
1 - Reverse rotate both stacks and log "rrr" if either one moved
2 - Reverse rotate stack a and log "rra"
3 - Reverse rotate stack b and log "rrb"
*/
void	ft_rr(t_data *data, char objetive)
{
	int	a;
	int	b;

	if (objetive == 'r')
	{
		a = ft_rrx(&data->a_top);
		b = ft_rrx(&data->b_top);
		if (a || b)
			log_op("rrr\n", 4, &data->count.rrr);
	}
	else if (objetive == 'a')
	{
		if (ft_rrx(&data->a_top))
			log_op("rra\n", 4, &data->count.rra);
	}
	else if (objetive == 'b')
	{
		if (ft_rrx(&data->b_top))
			log_op("rrb\n", 4, &data->count.rrb);
	}
}
