/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:01:53 by alvicent          #+#    #+#             */
/*   Updated: 2026/08/02 21:45:38 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Zero out the whole data structure to start from a clean state
2 - Enable adaptive mode by default (used when no strategy flag is given)
*/
void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->adaptative_mode = 1;
}

/*
1 - Compare every pair (i, j) of elements with i before j
2 - Count a mistake each time an earlier value is greater than a later one
3 - Count the total number of pairs examined
4 - Set disorder to 0 when there are no pairs
5 - Otherwise store the ratio mistakes / total_pairs (a value in [0, 1])
*/
void	init_disorder(t_data *data)
{
	t_stack	*i;
	t_stack	*j;
	int		mistakes;
	int		total;

	i = data->a_top;
	mistakes = 0;
	total = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		data->disorder = 0;
	else
		data->disorder = (double)mistakes / (double)total;
}

/*
1 - Repeat for every rank from 1 to size
2 - Find the smallest value that has not been indexed yet
3 - Assign the current rank as its sorted index
4 - Move on to the next rank until all nodes are indexed
*/
void	init_index(t_stack *top, int size)
{
	t_stack	*min;
	t_stack	*aux;
	int		index;

	index = 1;
	while (index <= size)
	{
		min = top;
		while (min->index != 0)
			min = min->next;
		aux = min;
		while (aux)
		{
			if (aux->index == 0 && aux->value < min->value)
				min = aux;
			aux = aux->next;
		}
		min->index = index;
		index++;
	}
}
