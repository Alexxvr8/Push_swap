/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 21:35:31 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:39:08 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
1 - Match a swap or push instruction and run it
2 - Return 1 on a match, 0 otherwise
*/
static int	apply_sp(t_data *data, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		return (ck_s(data, 'a'), 1);
	if (!ft_strncmp(line, "sb", 3))
		return (ck_s(data, 'b'), 1);
	if (!ft_strncmp(line, "ss", 3))
		return (ck_s(data, 's'), 1);
	if (!ft_strncmp(line, "pa", 3))
		return (ck_p(data, 'a'), 1);
	if (!ft_strncmp(line, "pb", 3))
		return (ck_p(data, 'b'), 1);
	return (0);
}

/*
1 - Match a rotate or reverse rotate instruction and run it
2 - Return 1 on a match, 0 otherwise
*/
static int	apply_rot(t_data *data, char *line)
{
	if (!ft_strncmp(line, "ra", 3))
		return (ck_r(data, 'a'), 1);
	if (!ft_strncmp(line, "rb", 3))
		return (ck_r(data, 'b'), 1);
	if (!ft_strncmp(line, "rr", 3))
		return (ck_r(data, 'r'), 1);
	if (!ft_strncmp(line, "rra", 4))
		return (ck_rr(data, 'a'), 1);
	if (!ft_strncmp(line, "rrb", 4))
		return (ck_rr(data, 'b'), 1);
	if (!ft_strncmp(line, "rrr", 4))
		return (ck_rr(data, 'r'), 1);
	return (0);
}

/*
1 - Try the swap/push instructions, then the rotate ones
2 - Return 1 if the line matched an operation, 0 if it is invalid
*/
int	apply_op(t_data *data, char *line)
{
	if (apply_sp(data, line))
		return (1);
	if (apply_rot(data, line))
		return (1);
	return (0);
}

/*
1 - Read one character at a time from standard input
2 - Return 0 on end of input with nothing read
3 - Stop at the newline and null-terminate the buffer
4 - Ignore any excess characters beyond the buffer size
*/
int	read_line(char *buf, int size)
{
	int		i;
	int		r;
	char	c;

	i = 0;
	r = read(0, &c, 1);
	if (r <= 0)
		return (0);
	while (r > 0 && c != '\n')
	{
		if (i < size - 1)
			buf[i++] = c;
		r = read(0, &c, 1);
	}
	buf[i] = '\0';
	return (1);
}

/*
1 - Walk the stack comparing each value with the next
2 - Return 0 as soon as a pair is out of order
3 - Return 1 when the whole stack is ascending
*/
int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
