/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:06:40 by alvicent          #+#    #+#             */
/*   Updated: 2026/08/02 21:45:06 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Convert the disorder ratio into hundredths of a percent, rounded
2 - Print the integer part, a dot and the two decimal digits
3 - Add a leading zero when the decimal part is a single digit
*/
static void	put_disorder(double disorder, int fd)
{
	int	percent;

	percent = (int)(disorder * 10000 + 0.5);
	ft_putnbr_fd(percent / 100, fd);
	ft_putstr_fd(".", fd);
	if (percent % 100 < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(percent % 100, fd);
	ft_putstr_fd("%\n", fd);
}

/*
1 - Print the strategy name (Adaptive or the forced one)
2 - Print the complexity class of the strategy actually used
*/
static void	put_strategy(t_data *data, int fd)
{
	if (data->adaptative_mode == 1)
		ft_putstr_fd("Adaptive / ", fd);
	else if (data->strategy == SIMPLE)
		ft_putstr_fd("Simple / ", fd);
	else if (data->strategy == MEDIUM)
		ft_putstr_fd("Medium / ", fd);
	else
		ft_putstr_fd("Complex / ", fd);
	if (data->strategy == SIMPLE)
		ft_putstr_fd("O(n^2)\n", fd);
	else if (data->strategy == MEDIUM)
		ft_putstr_fd("O(n*sqrt(n))\n", fd);
	else
		ft_putstr_fd("O(n log n)\n", fd);
}

/*
1 - Return the sum of every operation counter
*/
static int	total_ops(t_op_count *c)
{
	return (c->sa + c->sb + c->ss + c->pa + c->pb + c->ra
		+ c->rb + c->rr + c->rra + c->rrb + c->rrr);
}

/*
1 - Print one operation name followed by its count
*/
static void	put_op(char *name, int value, int fd)
{
	ft_putstr_fd(name, fd);
	ft_putnbr_fd(value, fd);
	ft_putstr_fd(" ", fd);
}

/*
1 - Print the disorder index as a percentage
2 - Print the strategy name and its complexity class
3 - Print the total number of operations
4 - Print the per-type counts, all to standard error
*/
void	print_bench(t_data *data)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	put_disorder(data->disorder, 2);
	ft_putstr_fd("[bench] strategy:  ", 2);
	put_strategy(data, 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_ops(&data->count), 2);
	ft_putstr_fd("\n[bench] ", 2);
	put_op("sa: ", data->count.sa, 2);
	put_op("sb: ", data->count.sb, 2);
	put_op("ss: ", data->count.ss, 2);
	put_op("pa: ", data->count.pa, 2);
	put_op("pb: ", data->count.pb, 2);
	ft_putstr_fd("\n[bench] ", 2);
	put_op("ra: ", data->count.ra, 2);
	put_op("rb: ", data->count.rb, 2);
	put_op("rr: ", data->count.rr, 2);
	put_op("rra: ", data->count.rra, 2);
	put_op("rrb: ", data->count.rrb, 2);
	put_op("rrr: ", data->count.rrr, 2);
	ft_putstr_fd("\n", 2);
}
