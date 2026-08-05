/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:02:38 by alvicent          #+#    #+#             */
/*   Updated: 2026/08/02 21:45:51 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Return immediately if no arguments are given
2 - Initialize the data structure to a clean state
3 - Parse the strategy/bench flags and get the first number index
4 - Return if there are no numbers to sort after the flags
5 - Parse and validate the numbers into stack a
6 - Assign a sorted index to every value and compute the disorder
7 - Run the selected sorting strategy only if the stack is not sorted
8 - Print the benchmark report if the --bench flag was set
9 - Free both stacks and exit
*/
int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 2)
		return (0);
	init_data(&data);
	i = parse_flags(&data, argc, argv);
	if (i >= argc)
		return (0);
	parse_nums(i, &data, argc, argv);
	init_index(data.a_top, data.size_a);
	init_disorder(&data);
	if (data.disorder != 0)
		select_algorithm(&data);
	if (data.bench_mode == 1)
		print_bench(&data);
	free_stack(data.a_top);
	free_stack(data.b_top);
	return (0);
}
