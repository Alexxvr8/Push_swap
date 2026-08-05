/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicent <alvicent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:08:26 by alvicent          #+#    #+#             */
/*   Updated: 2026/06/09 15:35:16 by alvicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
1 - Write the character to the specified file descriptor
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
