/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:11:09 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/22 16:51:03 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

/* ===== FT_PRINTF.C =====*/

int		ft_printf(char const *fmt, ...);

/* ===== FT_PRINT_CHAR.C =====*/

void	print_char(char c, int *len);
void	print_str(char *str, int *len);

/* ===== FT_PRINT_NBR.C =====*/

void	print_nbr(int n, int *len);
void	print_unbr(unsigned int n, int *len);
void	print_hex(unsigned long n, char type, int *len);
void	print_ptr(void *ptr, int *len);

#endif