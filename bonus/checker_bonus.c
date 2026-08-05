/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:31:50 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:38:16 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
1 - Skip any leading spaces
2 - Return true if the argument is empty or contains only spaces
*/
static int	arg_is_empty(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (s[i] == '\0');
}

/*
1 - Return immediately if no arguments are given
2 - Initialize the data structure
3 - Exit with an error on any empty argument
4 - Parse and validate the numbers into stack a
5 - Read operations from stdin and apply them one by one
6 - Exit with an error on any unknown instruction
7 - Print OK if a is sorted and b empty, KO otherwise
8 - Free both stacks and exit
*/
int	main(int argc, char **argv)
{
	t_data	data;
	char	line[8];
	int		i;

	if (argc < 2)
		return (0);
	init_data(&data);
	i = 0;
	while (++i < argc)
		if (arg_is_empty(argv[i]))
			error_exit(&data);
	parse_nums(1, &data, argc, argv);
	while (read_line(line, 8))
		if (!apply_op(&data, line))
			error_exit(&data);
	if (is_sorted(data.a_top) && data.b_top == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(data.a_top);
	free_stack(data.b_top);
	return (0);
}
