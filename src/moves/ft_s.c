/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 20:25:06 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:44:23 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Do nothing if the stack has fewer than two elements
2 - Swap the first two elements and fix their links
*/
static int	ft_sx(t_stack **top)
{
	t_stack	*aux;
	t_stack	*second;

	if (!(*top) ||!(*top)->next)
		return (0);
	aux = *top;
	second = aux->next;
	second->prev = NULL;
	aux->prev = second;
	aux->next = second->next;
	if (second->next)
		second->next->prev = aux;
	second->next = aux;
	*top = second;
	return (1);
}

/*
1 - Swap both stacks and log "ss" if either one moved
2 - Swap the first two of stack a and log "sa"
3 - Swap the first two of stack b and log "sb"
*/
void	ft_s(t_data *data, char objective)
{
	int	a;
	int	b;

	if (objective == 's')
	{
		a = ft_sx(&data->a_top);
		b = ft_sx(&data->b_top);
		if (a || b)
			log_op("ss\n", 3, &data->count.ss);
	}
	else if (objective == 'a')
	{
		if (ft_sx(&data->a_top))
			log_op("sa\n", 3, &data->count.sa);
	}
	else if (objective == 'b')
	{
		if (ft_sx(&data->b_top))
			log_op("sb\n", 3, &data->count.sb);
	}
}
