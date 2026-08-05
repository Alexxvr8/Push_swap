/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:00:58 by alvicent          #+#    #+#             */
/*   Updated: 2026/08/02 21:45:21 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Write "Error" followed by a newline to the standard error output
2 - Free both stacks if a data structure was provided
3 - Exit the program with a failure status
*/
void	error_exit(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	if (data)
	{
		free_stack(data->a_top);
		free_stack(data->b_top);
	}
	exit(1);
}
