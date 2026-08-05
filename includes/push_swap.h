/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:52:40 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:12:49 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <unistd.h>

// --- Nodo del stack ---
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				index;
}	t_stack;

// --- Contador de operaciones (bench mode) ---
typedef struct s_op_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_op_count;

// --- Estrategia elegida ---
typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

// --- Estructura central del programa ---
typedef struct s_data
{
	t_stack		*a_top;
	t_stack		*b_top;
	int			size_a;
	int			size_b;
	double		disorder;
	t_strategy	strategy;
	int			bench_mode;
	int			adaptative_mode;
	t_op_count	count;
}	t_data;

void	init_data(t_data *data);
void	init_index(t_stack *stop, int size);
void	init_disorder(t_data *data);

void	parse_nums(int i, t_data *data, int argc, char **argv);
int		parse_flags(t_data *data, int argc, char **argv);

void	select_algorithm(t_data *data);
void	ft_simple_algorithm(t_data *data);
void	ft_medium_algorithm(t_data *data);
void	ft_complex_algorithm(t_data *data);
void	print_bench(t_data *data);

void	log_op(char *op, int len, int *count);
t_stack	*lstnew(int nbr);
int		lstadd_back(t_stack **lst, t_stack *new);

void	error_exit(t_data *data);

void	free_stack(t_stack *top);
void	free_split(char **arr);

//--- INTERMEDIATE FUNCTIONS ---//

void	ft_s(t_data *data, char objetive);
void	ft_p(t_data *data, char objetive);
void	ft_r(t_data *data, char objetive);
void	ft_rr(t_data *data, char objetive);

#endif