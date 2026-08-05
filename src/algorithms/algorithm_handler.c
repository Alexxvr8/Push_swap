/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 13:26:32 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:42:07 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Run the simple, medium or complex algorithm based on the selected strategy
*/
static void	exec_algorithm(t_data *data)
{
	if (data->strategy == SIMPLE)
		ft_simple_algorithm(data);
	else if (data->strategy == MEDIUM)
		ft_medium_algorithm(data);
	else if (data->strategy == COMPLEX)
		ft_complex_algorithm(data);
}

/*
1 - In adaptive mode, choose the strategy from the disorder index
2 - Use Simple for low disorder, Medium for medium, Complex for high
3 - Execute the chosen strategy
*/
void	select_algorithm(t_data *data)
{
	if (data->adaptative_mode == 1)
	{
		if (data->disorder < 0.2)
			data->strategy = SIMPLE;
		else if (0.2 <= data->disorder && data->disorder < 0.5)
			data->strategy = MEDIUM;
		else if (0.5 <= data->disorder)
			data->strategy = COMPLEX;
	}
	exec_algorithm(data);
}
