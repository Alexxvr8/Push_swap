/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 22:19:40 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:43:54 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Do nothing if the stack has fewer than two elements
2 - Move the first element to the last position (rotate up)
*/
static int	ft_rx(t_stack **top)
{
	t_stack	*last;

	if (!(*top) || !(*top)->next)
		return (0);
	last = *top;
	while (last->next)
		last = last->next;
	last->next = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
	return (1);
}

/*
1 - Rotate both stacks and log "rr" if either one moved
2 - Rotate stack a and log "ra"
3 - Rotate stack b and log "rb"
*/
void	ft_r(t_data *data, char objetive)
{
	int	a;
	int	b;

	if (objetive == 'r')
	{
		a = ft_rx(&data->a_top);
		b = ft_rx(&data->b_top);
		if (a || b)
			log_op("rr\n", 3, &data->count.rr);
	}
	else if (objetive == 'a')
	{
		if (ft_rx(&data->a_top))
			log_op("ra\n", 3, &data->count.ra);
	}
	else if (objetive == 'b')
	{
		if (ft_rx(&data->b_top))
			log_op("rb\n", 3, &data->count.rb);
	}
}
