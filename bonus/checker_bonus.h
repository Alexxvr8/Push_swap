/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joserome <joserome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 21:36:30 by joserome          #+#    #+#             */
/*   Updated: 2026/08/02 21:15:35 by joserome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

void	ck_s(t_data *data, char obj);
void	ck_p(t_data *data, char obj);
void	ck_r(t_data *data, char obj);
void	ck_rr(t_data *data, char obj);
int		apply_op(t_data *data, char *line);
int		read_line(char *buf, int size);
int		is_sorted(t_stack *a);

#endif