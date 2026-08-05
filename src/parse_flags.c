/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 11:58:59 by alvicent          #+#    #+#             */
/*   Updated: 2026/08/02 21:46:18 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1 - Return true only when the argument starts with a double dash "--"
*/
static int	is_flag(const char *s)
{
	return (s[0] == '-' && s[1] == '-');
}

/*
1 - Return true if the argument matches one of the four strategy flags
*/
static int	is_strategy(const char *a)
{
	return (!ft_strncmp(a, "--simple", 9) || !ft_strncmp(a, "--medium", 9)
		|| !ft_strncmp(a, "--complex", 10) || !ft_strncmp(a, "--adaptive", 11));
}

/*
1 - Disable adaptive mode because an explicit strategy is being forced
2 - Select the matching strategy for --simple, --medium or --complex
3 - Re-enable adaptive mode for the --adaptive flag
*/
static void	apply_strategy(t_data *data, const char *arg)
{
	data->adaptative_mode = 0;
	if (!ft_strncmp(arg, "--simple", 9))
		data->strategy = SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		data->strategy = MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		data->strategy = COMPLEX;
	else
		data->adaptative_mode = 1;
}

/*
1 - Enable benchmark mode when the flag is --bench
2 - Count and apply the strategy when the flag is a strategy selector
3 - Exit with an error on any unknown flag
*/
static void	apply_flag(t_data *data, const char *arg, int *sel)
{
	if (!ft_strncmp(arg, "--bench", 8))
		data->bench_mode = 1;
	else if (is_strategy(arg))
	{
		(*sel)++;
		apply_strategy(data, arg);
	}
	else
		error_exit(data);
}

/*
1 - Read consecutive arguments while they look like flags
2 - Apply each flag (strategy selector or benchmark)
3 - Exit with an error if more than one strategy was selected
4 - Return the index of the first non-flag argument
*/
int	parse_flags(t_data *data, int argc, char **argv)
{
	int	i;
	int	sel;

	i = 1;
	sel = 0;
	while (i < argc && is_flag(argv[i]))
	{
		apply_flag(data, argv[i], &sel);
		i++;
	}
	if (sel > 1)
		error_exit(data);
	return (i);
}
