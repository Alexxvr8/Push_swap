/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_ops1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 21:35:56 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:39:33 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
1 - Do nothing if the stack has fewer than two elements
2 - Swap the first two elements and fix their links
*/
static int	s_swap(t_stack **top)
{
	t_stack	*aux;
	t_stack	*second;

	if (!(*top) || !(*top)->next)
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
1 - Do nothing if the source stack is empty
2 - Detach the top node of the source and place it on the destination
*/
static int	s_push(t_stack **from, t_stack **to)
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
1 - Silently swap stack a, stack b, or both (no output)
*/
void	ck_s(t_data *data, char obj)
{
	if (obj == 's')
	{
		s_swap(&data->a_top);
		s_swap(&data->b_top);
	}
	else if (obj == 'a')
		s_swap(&data->a_top);
	else if (obj == 'b')
		s_swap(&data->b_top);
}

/*
1 - Silently push between a and b in the requested direction
*/
void	ck_p(t_data *data, char obj)
{
	if (obj == 'a')
		s_push(&data->b_top, &data->a_top);
	else if (obj == 'b')
		s_push(&data->a_top, &data->b_top);
}
