/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:04:05 by alvicent          #+#    #+#             */
/*   Updated: 2026/08/02 21:46:48 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Skip an optional leading '+' or '-' sign
2 - Reject the string if the first character after the sign is not a digit
3 - Reject the string if any remaining character is not a digit
4 - Return 1 when the whole string is a valid integer
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
1 - Read an optional sign and remember it
2 - Accumulate the digits into a long value
3 - Flag an error if the running value goes out of the int range
4 - Return the signed value as an int
*/
static int	is_valid_num(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+' || s[i] == '-'))
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
1 - Iterate over every token of the split array
2 - Reject the input if a token is not a valid integer
3 - Convert the token and reject it on overflow
4 - Create a new node and fail on allocation error
5 - Append the node to stack a, rejecting duplicate values
6 - Increase the size of stack a
*/
static long	atoi_check(char *s, int *err)
{
	long	nbr;
	int		sign;
	int		i;

	i = 0;
	nbr = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		nbr = nbr * 10 + (s[i] - '0');
		if (nbr * sign < INT_MIN || INT_MAX < nbr * sign)
		{
			(*err) = 1;
			return (0);
		}
		i++;
	}
	return ((int)(nbr * sign));
}

/*
1 - Skip any leading spaces
2 - Return true if nothing but spaces was found (empty argument)
*/
static int	add_numbers(char **arr, t_data *data)
{
	long	nbr;
	int		j;
	int		err;
	t_stack	*node;

	j = 0;
	err = 0;
	while (arr[j])
	{
		if (!is_valid_num(arr[j]))
			return (0);
		nbr = atoi_check(arr[j], &err);
		if (err)
			return (0);
		node = lstnew((int)nbr);
		if (!node)
			return (0);
		if (!lstadd_back(&data->a_top, node))
			return (free(node), 0);
		data->size_a++;
		j++;
	}
	return (1);
}

/*
1 - Process every argument starting at the first number index
2 - Exit with an error if the argument is empty or only spaces
3 - Split the argument by spaces into individual tokens
4 - Exit with an error if the split allocation fails
5 - Add and validate the numbers, freeing and erroring on failure
6 - Free the split array and move to the next argument
*/
void	parse_nums(int i, t_data *data, int argc, char **argv)
{
	char	**arr;

	while (i < argc)
	{
		if (arg_is_empty(argv[i]))
			error_exit(data);
		arr = ft_split(argv[i], ' ');
		if (!arr)
			error_exit(data);
		if (!add_numbers(arr, data))
		{
			free_split(arr);
			error_exit(data);
		}
		free_split(arr);
		i++;
	}
}
