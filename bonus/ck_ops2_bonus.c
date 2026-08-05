/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_ops2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 20:01:37 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:40:16 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
1 - Do nothing if the stack has fewer than two elements
2 - Move the first element to the last position (rotate up)
*/
static int	s_rotate(t_stack **top)
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
1 - Do nothing if the stack has fewer than two elements
2 - Move the last element to the first position (reverse rotate)
*/
static int	s_rrotate(t_stack **top)
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
1 - Silently rotate stack a, stack b, or both (no output)
*/
void	ck_r(t_data *data, char obj)
{
	if (obj == 'r')
	{
		s_rotate(&data->a_top);
		s_rotate(&data->b_top);
	}
	else if (obj == 'a')
		s_rotate(&data->a_top);
	else if (obj == 'b')
		s_rotate(&data->b_top);
}

/*
1 - Silently reverse rotate stack a, stack b, or both (no output)
*/
void	ck_rr(t_data *data, char obj)
{
	if (obj == 'r')
	{
		s_rrotate(&data->a_top);
		s_rrotate(&data->b_top);
	}
	else if (obj == 'a')
		s_rrotate(&data->a_top);
	else if (obj == 'b')
		s_rrotate(&data->b_top);
}
