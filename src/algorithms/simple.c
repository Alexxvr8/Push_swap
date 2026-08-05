/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:08:01 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:43:23 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Read the sorted indexes of the three top elements
2 - Apply the swap/rotate combination that orders those three cases
*/
static void	sort_three(t_data *data)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = data->a_top->index;
	i2 = data->a_top->next->index;
	i3 = data->a_top->next->next->index;
	if (i1 > i2 && i2 < i3 && i1 < i3)
		ft_s(data, 'a');
	else if (i1 > i2 && i2 > i3)
	{
		ft_s(data, 'a');
		ft_rr(data, 'a');
	}
	else if (i1 > i2 && i1 > i3)
		ft_r(data, 'a');
	else if (i1 < i2 && i1 < i3)
	{
		ft_s(data, 'a');
		ft_r(data, 'a');
	}
	else
		ft_rr(data, 'a');
}

/*
1 - Return handled for sizes 0 and 1 (already sorted)
2 - Swap the two elements for size 2
3 - Call sort_three for size 3
4 - Return 0 when the size is larger and needs the main algorithm
*/
static int	sort_small(t_data *data)
{
	if (data->size_a <= 1)
		return (1);
	if (data->size_a == 2)
	{
		ft_s(data, 'a');
		return (1);
	}
	if (data->size_a == 3)
	{
		sort_three(data);
		return (1);
	}
	return (0);
}

/*
1 - Locate the node whose index equals the target and its position
2 - Rotate up (ra) if the node is in the upper half
3 - Reverse rotate (rra) otherwise, taking the shorter path
*/
static void	bring_to_top(t_data *data, int target)
{
	t_stack	*current;
	int		pos;

	current = data->a_top;
	pos = 0;
	while (current->index != target)
	{
		current = current->next;
		pos++;
	}
	if (pos <= data->size_a / 2)
		while (pos--)
			ft_r(data, 'a');
	else
		while (pos++ < data->size_a)
			ft_rr(data, 'a');
}

/*
1 - Handle the small cases and return early if solved
2 - For each index in order, bring it to the top and push it to b
3 - Push every element back from b to a, leaving a sorted
*/
void	ft_simple_algorithm(t_data *data)
{
	int	total;
	int	target;

	if (sort_small(data))
		return ;
	target = 1;
	total = data->size_a;
	while (target <= total)
	{
		bring_to_top(data, target);
		ft_p(data, 'b');
		target++;
	}
	while (data->size_b > 0)
		ft_p(data, 'a');
}
